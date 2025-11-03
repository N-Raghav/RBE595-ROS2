#pragma once


#include <memory>
#include <string>
#include <vector>
#include <map>


// ROS2
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"


// MoveIt
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>


// Messages and Services
#include "geometry_msgs/msg/pose.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "franka_control/srv/panda_srv.hpp"
#include "franka_msgs/action/grasp.hpp"
#include "franka_msgs/action/move.hpp"


// Math
#include <Eigen/Dense>


class PandaControlNode : public rclcpp::Node {
public:
PandaControlNode();


private:
// Delayed initialization (to safely use shared_from_this)
void init_moveit_and_scene();


// Service callback
void pickAndPlaceCallback(
const std::shared_ptr<franka_control::srv::PandaSrv::Request> request,
std::shared_ptr<franka_control::srv::PandaSrv::Response> response);


// Core motion functions
bool move_joint(const std::vector<double> &joint_positions);
bool move_pose(const geometry_msgs::msg::Pose &pose);
bool execute_traj_start(const std::vector<double> &pose_and_angle);


// Helper functions
void set_def_pos();
bool grasp(double width_m);
bool open_gripper(double width_m);
void add_all_collision_objects();
Eigen::Vector3d tf_cam_to_panda(const Eigen::Vector3d &pos_in_cam) const;


// State getters
geometry_msgs::msg::Pose get_current_pose() const;
std::vector<double> get_current_joints() const;


// Member variables
rclcpp::Service<franka_control::srv::PandaSrv>::SharedPtr service_;


rclcpp_action::Client<franka_msgs::action::Grasp>::SharedPtr grasp_client_;
rclcpp_action::Client<franka_msgs::action::Move>::SharedPtr move_client_;


using MoveGroupInterfacePtr =
std::shared_ptr<moveit::planning_interface::MoveGroupInterface>;
MoveGroupInterfacePtr move_group_arm_;
MoveGroupInterfacePtr move_group_hand_;
std::shared_ptr<moveit::planning_interface::PlanningSceneInterface>
planning_scene_interface_;


Eigen::Matrix4d T_cam_to_base_;
std::map<std::string, geometry_msgs::msg::Pose> drop_locations_;


// one-shot timer to defer MoveIt init until after shared_ptr is established
rclcpp::TimerBase::SharedPtr init_timer_;
};