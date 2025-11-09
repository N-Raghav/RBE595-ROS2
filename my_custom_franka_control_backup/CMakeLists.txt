cmake_minimum_required(VERSION 3.8)
project(franka_control)

# --------------------------------------------------
# Dependencies
# --------------------------------------------------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(franka_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# --------------------------------------------------
# Generate custom service (PandaSrv.srv)
# --------------------------------------------------
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/PandaSrv.srv"
  DEPENDENCIES std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

# --------------------------------------------------
# Build the Panda control node
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

# Link node to generated interfaces
rosidl_target_interfaces(panda_control_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp"
)

# --------------------------------------------------
# Install Targets and Resources
# --------------------------------------------------
# Node
install(TARGETS
  panda_control_node
  DESTINATION lib/${PROJECT_NAME}
)

# Launch files
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# Service definitions (for introspection or testing)
install(
  DIRECTORY srv
  DESTINATION share/${PROJECT_NAME}
)

# --------------------------------------------------
# Package export
# --------------------------------------------------
ament_package()
