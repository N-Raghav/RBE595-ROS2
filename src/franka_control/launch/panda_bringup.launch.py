from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # ---------------------------------------------------------------
    # 1. Launch Arguments
    # ---------------------------------------------------------------
    declare_args = [
        DeclareLaunchArgument(
            "robot_ip",
            default_value="172.16.0.2",
            description="IP address of the Franka robot (used only for real hardware)"
        ),
        DeclareLaunchArgument(
            "use_fake_hardware",
            default_value="true",
            description="Use FakeSystem (sim) or real FrankaHW interface"
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

    # ---------------------------------------------------------------
    # 2. Package Paths
    # ---------------------------------------------------------------
    franka_desc_pkg = get_package_share_directory("franka_description")
    franka_moveit_pkg = get_package_share_directory("franka_moveit_config")

    # ---------------------------------------------------------------
    # 3. Robot Description (URDF + Xacro)
    # ---------------------------------------------------------------
    urdf_path = PathJoinSubstitution([franka_desc_pkg, "urdf", "panda.urdf.xacro"])
    robot_description = Command([
        "xacro ", urdf_path,
        " use_fake_hardware:=", use_fake_hardware,
        " robot_ip:=", robot_ip
    ])

    # ---------------------------------------------------------------
    # 4. Controller Configuration
    # ---------------------------------------------------------------
    controller_config = PathJoinSubstitution([
        franka_desc_pkg,
        "config",
        "ros2_controllers.yaml"
    ])

    # ---------------------------------------------------------------
    # 5. Core Nodes
    # ---------------------------------------------------------------

    # Robot State Publisher
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
        output="screen"
    )

    # ROS 2 Control Node
    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[{"robot_description": robot_description}, controller_config],
        output="screen"
    )

    # Controllers (spawners)
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

    # MoveIt 2 move_group Launch
    move_group_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([franka_moveit_pkg, "launch", "move_group.launch.py"])
        ]),
        launch_arguments={
            "use_sim_time": "true",
            "allow_trajectory_execution": "true"
        }.items()
    )

    # RViz 2 Visualization (conditional)
    rviz = Node(
        package="rviz2",
        executable="rviz2",
        arguments=["-d", PathJoinSubstitution([franka_moveit_pkg, "launch", "moveit_rviz.launch.py"])],
        condition=IfCondition(use_rviz),
        output="screen"
    )

    # ---------------------------------------------------------------
    # 6. Launch Everything
    # ---------------------------------------------------------------
    return LaunchDescription(
        declare_args + [
            robot_state_publisher,
            control_node,
            joint_state_broadcaster,
            panda_arm_controller,
            move_group_launch,
            rviz
        ]
    )
