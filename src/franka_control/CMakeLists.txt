cmake_minimum_required(VERSION 3.8)
project(franka_control)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(franka_msgs REQUIRED)    # For gripper action messages
find_package(Eigen3 REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)       # Used in your service

# Generate the custom service
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/PandaSrv.srv"
  DEPENDENCIES std_msgs
)

# Get the C++ typesupport target for linking
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp"
)

# Build the Panda control node
add_executable(panda_control_node
  src/panda_control_node.cpp
)

target_include_directories(panda_control_node
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(panda_control_node
  rclcpp
  rclcpp_action
  std_msgs
  moveit_ros_planning_interface
  geometry_msgs
  franka_msgs
  Eigen3
)

# Link node against generated service code
target_link_libraries(panda_control_node
  ${cpp_typesupport_target}
)

# Install executable
install(TARGETS panda_control_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files if present
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
