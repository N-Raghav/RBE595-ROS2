#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/float64.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <franka_msgs/action/grasp.hpp>
#include <franka_msgs/action/move.hpp>

#include <chrono>
#include <future>
#include <cmath>

#include "franka_control/srv/panda_srv.hpp"

using namespace std::chrono_literals;

class PandaControlNode : public rclcpp::Node {
public:
  PandaControlNode() : Node("panda_control") {
    // Parameters
    planning_group_       = declare_parameter<std::string>("planning_group", "panda_arm");
    base_frame_           = declare_parameter<std::string>("base_frame", "panda_link0");
    ee_link_              = declare_parameter<std::string>("ee_link", "panda_hand_tcp");
    approach_dist_        = declare_parameter<double>("approach_distance", 0.10);
    retreat_dist_         = declare_parameter<double>("retreat_distance", 0.10);
    velocity_scaling_     = declare_parameter<double>("velocity_scaling", 0.2);
    acceleration_scaling_ = declare_parameter<double>("acceleration_scaling", 0.2);
    use_gripper_          = declare_parameter<bool>("use_gripper", false);   // 👈 new

    // Only create action clients if we actually want to use the gripper
    if (use_gripper_) {
      grasp_client_ = rclcpp_action::create_client<franka_msgs::action::Grasp>(this, "/franka_gripper/grasp");
      move_client_  = rclcpp_action::create_client<franka_msgs::action::Move>(this, "/franka_gripper/move");
    }

    srv_ = create_service<franka_control::srv::PandaSrv>(
      "panda_control_service",
      std::bind(&PandaControlNode::handle_service, this,
                std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    RCLCPP_INFO(get_logger(), "PandaControlNode constructed (MoveGroup not initialized yet).");
  }

  void initialize_move_group() {
    auto node_ptr = std::shared_ptr<rclcpp::Node>(this, [](rclcpp::Node*){});
    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(node_ptr, planning_group_);
    move_group_->setEndEffectorLink(ee_link_);
    move_group_->setMaxVelocityScalingFactor(velocity_scaling_);
    move_group_->setMaxAccelerationScalingFactor(acceleration_scaling_);
    move_group_->setPlanningTime(5.0);
    RCLCPP_INFO(get_logger(), "MoveGroup initialized for planning group: %s", planning_group_.c_str());
  }

private:
  // Members
  std::string planning_group_, base_frame_, ee_link_;
  double approach_dist_, retreat_dist_, velocity_scaling_, acceleration_scaling_;
  bool use_gripper_{false};

  rclcpp::Service<franka_control::srv::PandaSrv>::SharedPtr srv_;
  std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
  rclcpp_action::Client<franka_msgs::action::Grasp>::SharedPtr grasp_client_;
  rclcpp_action::Client<franka_msgs::action::Move>::SharedPtr  move_client_;

  void handle_service(const std::shared_ptr<rmw_request_id_t> /*header*/,
                      const std::shared_ptr<franka_control::srv::PandaSrv::Request> req,
                      std::shared_ptr<franka_control::srv::PandaSrv::Response> res)
  {
    const auto &vec = req->grasps.data;
    if (vec.size() < 6 || (vec.size() % 6) != 0) {
      RCLCPP_ERROR(get_logger(), "Request must contain N*6 elements: [x,y,z,yaw,width,label]...");
      res->flag.data = 0.0;
      return;
    }

    if (!move_group_) {
      RCLCPP_ERROR(get_logger(), "MoveGroup not initialized.");
      res->flag.data = 0.0;
      return;
    }

    // If we DO want a gripper, but it's not up, warn, but don't kill motion
    if (use_gripper_) {
      bool have_gripper_servers =
        move_client_ && grasp_client_ &&
        move_client_->wait_for_action_server(500ms) &&
        grasp_client_->wait_for_action_server(500ms);
      if (!have_gripper_servers) {
        RCLCPP_WARN(get_logger(), "use_gripper=true but gripper action servers not available. Continuing with motion only.");
      }
    }

    bool any_success = false;
    for (size_t i = 0; i < vec.size(); i += 6) {
      const double x     = vec[i + 0];
      const double y     = vec[i + 1];
      const double z     = vec[i + 2];
      const double yaw   = vec[i + 3];
      const double width = vec[i + 4];
      const int    label = static_cast<int>(vec[i + 5]);
      (void)label; // not used yet

      RCLCPP_INFO(get_logger(),
                  "Trying grasp #%zu: (%.3f, %.3f, %.3f), yaw=%.2f, width=%.3f",
                  i/6, x, y, z, yaw, width);

      if (try_one_grasp(x, y, z, yaw, width)) {
        any_success = true;
        break;
      }
    }

    res->flag.data = any_success ? 1.0 : 0.0;
  }

  bool try_one_grasp(double x, double y, double z, double yaw, double width) {
    constexpr double PI = 3.14159265358979323846;

    // approach
    geometry_msgs::msg::PoseStamped approach;
    approach.header.frame_id = base_frame_;
    approach.header.stamp = now();
    approach.pose.position.x = x;
    approach.pose.position.y = y;
    approach.pose.position.z = z + approach_dist_;
    tf2::Quaternion q; q.setRPY(PI, 0.0, yaw);
    approach.pose.orientation = tf2::toMsg(q);

    // target
    geometry_msgs::msg::PoseStamped target = approach;
    target.pose.position.z = z;

    // retreat
    geometry_msgs::msg::PoseStamped retreat = target;
    retreat.pose.position.z = z + retreat_dist_;

    // (optional) open gripper BEFORE approach
    if (use_gripper_) {
      if (!open_gripper(width)) {
        RCLCPP_WARN(get_logger(), "open_gripper() failed, continuing with motion.");
      }
    }

    if (!plan_and_execute_to(approach)) return false;
    if (!plan_and_execute_to(target))   return false;

    // (optional) grasp
    if (use_gripper_) {
      if (!grasp(width)) {
        RCLCPP_WARN(get_logger(), "grasp() failed, continuing with motion.");
      }
    }

    if (!plan_and_execute_to(retreat))  return false;

    return true;
  }

  bool plan_and_execute_to(const geometry_msgs::msg::PoseStamped& goal_pose) {
    move_group_->setPoseTarget(goal_pose, ee_link_);
    moveit::planning_interface::MoveGroupInterface::Plan plan;

    const bool planned =
      (move_group_->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    if (!planned) {
      RCLCPP_ERROR(get_logger(), "Planning failed.");
      move_group_->clearPoseTargets();
      return false;
    }
    const bool executed =
      (move_group_->execute(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    move_group_->clearPoseTargets();
    if (!executed) {
      RCLCPP_ERROR(get_logger(), "Execution failed.");
      return false;
    }
    return true;
  }

  // ===== Gripper helpers (used only if use_gripper_ == true) =====
  bool open_gripper(double width_m) {
    if (!use_gripper_ || !move_client_) return true;
    franka_msgs::action::Move::Goal goal;
    goal.width = width_m;

    auto ghf = move_client_->async_send_goal(goal);
    if (ghf.wait_for(5s) != std::future_status::ready) return false;
    auto gh = ghf.get(); if (!gh) return false;

    auto rf = move_client_->async_get_result(gh);
    if (rf.wait_for(10s) != std::future_status::ready) return false;
    return (rf.get().code == rclcpp_action::ResultCode::SUCCEEDED);
  }

  bool grasp(double width_m) {
    if (!use_gripper_ || !grasp_client_) return true;
    franka_msgs::action::Grasp::Goal goal;
    goal.width  = width_m;
    goal.speed  = 0.05;
    goal.force  = 20.0;
    goal.epsilon.inner = 0.005;
    goal.epsilon.outer = 0.005;

    auto ghf = grasp_client_->async_send_goal(goal);
    if (ghf.wait_for(5s) != std::future_status::ready) return false;
    auto gh = ghf.get(); if (!gh) return false;

    auto rf = grasp_client_->async_get_result(gh);
    if (rf.wait_for(15s) != std::future_status::ready) return false;
    return (rf.get().code == rclcpp_action::ResultCode::SUCCEEDED);
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PandaControlNode>();
  node->initialize_move_group();
  rclcpp::executors::MultiThreadedExecutor exec;
  exec.add_node(node);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}
