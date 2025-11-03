cmake_minimum_required(VERSION 3.8)
project(franka_control)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(franka_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# --------------------------------------------------
# Generate the custom service
# --------------------------------------------------
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/PandaSrv.srv"
  DEPENDENCIES std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

# --------------------------------------------------
# Executable
# --------------------------------------------------
add_executable(panda_control_node src/panda_control_node.cpp)
ament_target_dependencies(panda_control_node
  rclcpp
  rclcpp_action
  std_msgs
  geometry_msgs
  moveit_ros_planning_interface
  franka_msgs
)

# link node to generated interfaces
rosidl_target_interfaces(panda_control_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

# --------------------------------------------------
# Install
# --------------------------------------------------
install(TARGETS
  panda_control_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
