from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    franka_control_pkg = get_package_share_directory("franka_control")
    franka_moveit_pkg  = get_package_share_directory("franka_moveit_config")

    bringup = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([franka_control_pkg, "launch", "panda_bringup.launch.py"])
        )
    )

    move_group = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([franka_moveit_pkg, "launch", "move_group.launch.py"])
        )
    )

    return LaunchDescription([bringup, move_group])
