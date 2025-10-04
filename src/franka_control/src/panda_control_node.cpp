#include "franka_control/panda_control_node.hpp"

using namespace std::chrono_literals;

static const std::string PANDA_ARM_GROUP = "panda_arm";
static const std::string PANDA_HAND_GROUP = "panda_hand";
const double GRIPPER_OPEN = 0.08;

PandaControlNode::PandaControlNode()
: Node("panda_control_node")
{
    // Transformation matrix
    T_cam_to_base_ << 1, 0, 0, 0.53195,
                      0, -1, 0, 0.12044,
                      0, 0, -1, 0.92949,
                      0, 0, 0, 1.0;

    // Drop-off location
    geometry_msgs::msg::Pose plastic_pose;
    plastic_pose.position.x = 0.0;
    plastic_pose.position.y = -0.3;
    plastic_pose.position.z = 0.5;
    plastic_pose.orientation.w = 1.0;
    drop_locations_["plastic"] = plastic_pose;

    // Initialize MoveIt interfaces
    auto node_ptr = shared_from_this();
    move_group_arm_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(node_ptr, PANDA_ARM_GROUP);
    move_group_hand_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(node_ptr, PANDA_HAND_GROUP);
    planning_scene_interface_ = std::make_shared<moveit::planning_interface::PlanningSceneInterface>();

    move_group_arm_->allowReplanning(true);
    move_group_arm_->setPlanningTime(30.0);
    move_group_arm_->setNumPlanningAttempts(20);

    // Initialize service
    using std::placeholders::_1;
    using std::placeholders::_2;
    service_ = this->create_service<franka_control::srv::PandaSrv>(
        "panda_control",
        std::bind(&PandaControlNode::pickAndPlaceCallback, this, _1, _2)
    );

    // Initialize action client
    grasp_client_ = rclcpp_action::create_client<franka_msgs::action::Grasp>(
        this, "/franka_gripper/grasp"
    );

    // Remove old collision objects and add new ones
    planning_scene_interface_->removeCollisionObjects(planning_scene_interface_->getKnownObjectNames());
    add_all_collision_objects();

    // Move to default position and open gripper
    set_def_pos();
    grasp(GRIPPER_OPEN);

    RCLCPP_INFO(this->get_logger(), "Panda Control Node initialized.");
}

void PandaControlNode::pickAndPlaceCallback(
    const std::shared_ptr<franka_control::srv::PandaSrv::Request> request,
    std::shared_ptr<franka_control::srv::PandaSrv::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Received pick and place request.");
    const auto& grasp_data = request->grasps.data;
    if (grasp_data.size() < 5) {
        RCLCPP_ERROR(this->get_logger(), "Grasp data is too small.");
        response->flag.data = 0;
        return;
    }

    double width_offset = 0.005;
    double height_offset = 0.09;

    double object_width = grasp_data[4];
    double object_angle = grasp_data[3];
    Eigen::Vector3d pos_in_cam(grasp_data[0], grasp_data[1], grasp_data[2]);
    Eigen::Vector3d transformed_pos = tf_cam_to_panda(pos_in_cam);

    std::vector<double> grasp_target = {transformed_pos.x(), transformed_pos.y(), transformed_pos.z() + height_offset, object_angle};
    std::vector<double> pre_grasp_target = {transformed_pos.x(), transformed_pos.y(), transformed_pos.z() + 0.2, object_angle};

    bool success = true;
    success &= execute_traj_start(pre_grasp_target);
    success &= execute_traj_start(grasp_target);
    grasp(object_width - width_offset);
    success &= execute_traj_start(pre_grasp_target);
    success &= move_pose(drop_locations_["plastic"]);
    grasp(GRIPPER_OPEN);
    set_def_pos();

    response->flag.data = success ? 1 : 0;
}

// ---------------- Core motion functions ----------------

bool PandaControlNode::move_joint(const std::vector<double>& joint_positions)
{
    move_group_arm_->setJointValueTarget(joint_positions);
    return move_group_arm_->move() == moveit::core::MoveItErrorCode::SUCCESS;
}

bool PandaControlNode::move_pose(const geometry_msgs::msg::Pose& pose)
{
    move_group_arm_->setPoseTarget(pose);
    return move_group_arm_->move() == moveit::core::MoveItErrorCode::SUCCESS;
}

bool PandaControlNode::execute_traj_start(const std::vector<double>& pose_and_angle)
{
    geometry_msgs::msg::Pose target_pose;
    target_pose.position.x = pose_and_angle[0];
    target_pose.position.y = pose_and_angle[1];
    target_pose.position.z = pose_and_angle[2];
    double angle = pose_and_angle[3];

    Eigen::Matrix3d R_cam_to_base = T_cam_to_base_.block<3,3>(0,0);
    Eigen::Matrix3d R_angle = Eigen::AngleAxisd(angle, Eigen::Vector3d::UnitZ()).toRotationMatrix();
    Eigen::Quaterniond q(R_angle * R_cam_to_base);
    q.normalize();

    target_pose.orientation.x = q.x();
    target_pose.orientation.y = q.y();
    target_pose.orientation.z = q.z();
    target_pose.orientation.w = q.w();

    std::vector<geometry_msgs::msg::Pose> waypoints = {target_pose};
    moveit_msgs::msg::RobotTrajectory trajectory;
    double fraction = move_group_arm_->computeCartesianPath(waypoints, 0.01, 0.0, trajectory);

    if (fraction < 0.9) {
        RCLCPP_ERROR(this->get_logger(), "Cartesian path failed, fraction = %f", fraction);
        return false;
    }

    return move_group_arm_->execute(trajectory) == moveit::core::MoveItErrorCode::SUCCESS;
}

// ---------------- Helpers ----------------

Eigen::Vector3d PandaControlNode::tf_cam_to_panda(const Eigen::Vector3d& pos_in_cam) const
{
    Eigen::Vector4d p_cam(pos_in_cam.x(), pos_in_cam.y(), pos_in_cam.z(), 1.0);
    Eigen::Vector4d p_panda = T_cam_to_base_ * p_cam;
    return p_panda.head<3>();
}

geometry_msgs::msg::Pose PandaControlNode::get_current_pose() const
{
    return move_group_arm_->getCurrentPose().pose;
}

std::vector<double> PandaControlNode::get_current_joints() const
{
    return move_group_arm_->getCurrentJointValues();
}

void PandaControlNode::grasp(double width)
{
    if (!grasp_client_->wait_for_action_server(5s)) {
        RCLCPP_ERROR(this->get_logger(), "Grasp action server not available.");
        return;
    }

    franka_msgs::action::Grasp::Goal goal_msg;
    goal_msg.width = width;
    goal_msg.speed = 0.2;
    goal_msg.force = 0.7;
    goal_msg.epsilon.inner = 0.5;
    goal_msg.epsilon.outer = 0.5;

    auto send_goal_options = rclcpp_action::Client<franka_msgs::action::Grasp>::SendGoalOptions();
    send_goal_options.result_callback = [](auto) {};

    grasp_client_->async_send_goal(goal_msg, send_goal_options);
    rclcpp::sleep_for(500ms);
}

void PandaControlNode::set_def_pos()
{
    std::vector<double> home_joints = {-0.466, -1.294, 0.218, -2.640, 0.199, 1.363, 0.423};
    move_joint(home_joints);
}

void PandaControlNode::add_all_collision_objects()
{
    auto create_box = [&](const std::string& id, double x, double y, double z, double dx, double dy, double dz) {
        moveit_msgs::msg::CollisionObject obj;
        obj.header.frame_id = move_group_arm_->getPlanningFrame();
        obj.id = id;

        shape_msgs::msg::SolidPrimitive primitive;
        primitive.type = primitive.BOX;
        primitive.dimensions = {dx, dy, dz};

        geometry_msgs::msg::Pose box_pose;
        box_pose.position.x = x;
        box_pose.position.y = y;
        box_pose.position.z = z;
        box_pose.orientation.w = 1.0;

        obj.primitives.push_back(primitive);
        obj.primitive_poses.push_back(box_pose);
        obj.operation = obj.ADD;

        return obj;
    };

    std::vector<moveit_msgs::msg::CollisionObject> collision_objects;
    collision_objects.push_back(create_box("coveyor", 0.535, 0.0, 0.045, 0.85, 1.80, 0.09));
    collision_objects.push_back(create_box("vbar", 0.889, 0.0, 0.51, 0.04, 0.04, 0.84));
    collision_objects.push_back(create_box("hbar", 0.615, 0.0, 0.94, 0.55, 0.04, 0.04));
    collision_objects.push_back(create_box("camera", 0.505, 0.0, 0.905, 0.095, 0.078, 0.050));
    collision_objects.push_back(create_box("back_wall", -0.950, 0.0, 0.5, 0.05, 2.0, 1.0));
    collision_objects.push_back(create_box("side_wall1", 0.535, 0.83, 0.5, 1.0, 0.05, 1.0));
    collision_objects.push_back(create_box("side_wall2", 0.535, -0.63, 0.5, 1.0, 0.05, 1.0));

    planning_scene_interface_->addCollisionObjects(collision_objects);
}

// ---------------- Main ----------------

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PandaControlNode>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
