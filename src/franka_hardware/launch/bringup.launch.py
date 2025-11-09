import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # ---------------------------------------------------------------
    # 1. Launch Arguments
    # ---------------------------------------------------------------
    robot_ip = LaunchConfiguration('robot_ip')
    declare_robot_ip = DeclareLaunchArgument(
        'robot_ip',
        default_value='172.16.0.2',
        description='IP address of the Franka Panda robot (ignored for FakeSystem)'
    )

    # ---------------------------------------------------------------
    # 2. Package Directories
    # ---------------------------------------------------------------
    franka_desc_pkg = get_package_share_directory('franka_description')

    # ---------------------------------------------------------------
    # 3. Robot Description (URDF/Xacro)
    # ---------------------------------------------------------------
    panda_xacro = PathJoinSubstitution([
        franka_desc_pkg,
        'urdf',
        'panda.urdf.xacro'
    ])

    robot_description = ParameterValue(
        Command(['xacro ', panda_xacro]),
        value_type=str
    )

    # ---------------------------------------------------------------
    # 4. Controller Configuration (YAML)
    # ---------------------------------------------------------------
    ros2_control_config = PathJoinSubstitution([
        franka_desc_pkg,
        'config',
        'ros2_controllers.yaml'
    ])

    # ---------------------------------------------------------------
    # 5. Nodes
    # ---------------------------------------------------------------

    # Controller manager node
    control_node = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[
            {'robot_description': robot_description},
            ros2_control_config
        ],
        output='screen'
    )

    # Joint state broadcaster
    joint_state_broadcaster = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'],
        output='screen'
    )

    # Arm controller
    arm_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['panda_arm_controller', '--controller-manager', '/controller_manager'],
        output='screen'
    )

    # Gripper (optional for now — won’t affect bringup)
    hand_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['hand_controller', '--controller-manager', '/controller_manager'],
        output='screen'
    )

    # ---------------------------------------------------------------
    # 6. Launch Description
    # ---------------------------------------------------------------
    return LaunchDescription([
        declare_robot_ip,
        control_node,
        joint_state_broadcaster,
        arm_spawner,
        # Comment this out until gripper is ready
        # hand_spawner
    ])
