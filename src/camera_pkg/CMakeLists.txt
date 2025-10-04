cmake_minimum_required(VERSION 3.8)

project(camera_pkg)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED) # For Python packages
find_package(rosidl_default_generators REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)

# Generate Python code from .srv files
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/CameraSrv.srv"
  DEPENDENCIES sensor_msgs builtin_interfaces
)

# Install Python modules
ament_python_install_package(${PROJECT_NAME})

# Standard ament package macro
ament_package()
