from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Get package paths
    franka_gazebo_pkg = get_package_share_directory('franka_gazebo')
    franka_moveit_pkg = get_package_share_directory('franka_moveit_config')

    # Launch Gazebo with Panda
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(franka_gazebo_pkg, 'launch', 'panda_world.launch.py')
        )
    )

    # Launch MoveIt with sim:=true
    moveit_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(franka_moveit_pkg, 'launch', 'moveit_planning_execution.launch.py')
        ),
        launch_arguments={'sim': 'true'}.items()
    )

    # Launch your panda_control_node
    panda_control_node = Node(
        package='franka_control',
        executable='panda_control_node',
        output='screen'
    )

    return LaunchDescription([
        gazebo_launch,
        moveit_launch,
        panda_control_node
    ])
