from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch.conditions import IfCondition
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get package paths
    franka_desc_pkg = get_package_share_directory("franka_description")

    # Robot IP (used later for real hardware)
    declared_arguments = [
        DeclareLaunchArgument(
            "robot_ip",
            default_value="172.16.0.2",
            description="IP address of the Franka robot"
        ),
        DeclareLaunchArgument(
            "use_fake_hardware",
            default_value="true",
            description="Whether to use FakeSystem or real FrankaHW"
        ),
        DeclareLaunchArgument(
            "use_rviz",
            default_value="true",
            description="Whether to start RViz2"
        )
    ]

    robot_ip = LaunchConfiguration("robot_ip")
    use_fake_hardware = LaunchConfiguration("use_fake_hardware")
    use_rviz = LaunchConfiguration("use_rviz")

    # URDF/Xacro description
    urdf_path = PathJoinSubstitution(
        [franka_desc_pkg, "urdf", "panda.urdf.xacro"]
    )

    robot_description = Command([
        "xacro ", urdf_path,
        " use_fake_hardware:=", use_fake_hardware,
        " robot_ip:=", robot_ip
    ])

    # Controller configuration YAML
    controller_config = PathJoinSubstitution(
        [franka_desc_pkg, "config", "ros2_controllers.yaml"]
    )

    # ros2_control_node (core)
    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[
            {"robot_description": robot_description},
            controller_config
        ],
        output="screen"
    )

    # Spawners
    joint_state_broadcaster = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "--controller-manager", "/controller_manager"],
        output="screen"
    )

    panda_arm_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["panda_arm_controller", "--controller-manager", "/controller_manager"],
        output="screen"
    )

    # RViz + robot_state_publisher
    robot_state_pub = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
        output="screen"
    )
    rviz = Node(
    package="rviz2",
    executable="rviz2",
    arguments=["-d", PathJoinSubstitution([franka_desc_pkg, "rviz", "panda.rviz"])],
    condition=IfCondition(use_rviz),
    output="screen"
  )


    return LaunchDescription(
        declared_arguments + [
            control_node,
            joint_state_broadcaster,
            panda_arm_controller,
            robot_state_pub,
            rviz,
        ]
    )
