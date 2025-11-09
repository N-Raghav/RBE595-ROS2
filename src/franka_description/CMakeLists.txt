cmake_minimum_required(VERSION 3.8)
project(franka_description)

find_package(ament_cmake REQUIRED)

# Install both config and urdf into the package share directory
install(
  DIRECTORY config urdf
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
