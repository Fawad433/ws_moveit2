import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from ament_index_python.packages import get_package_share_directory
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    moveit_config = (
        MoveItConfigsBuilder("myrobot")
        .robot_description(file_path="config/my_robot.urdf.xacro")
        .trajectory_execution(file_path="config/gripper_moveit_controllers.yaml")
        .planning_pipelines(pipelines=["ompl"])
        .to_moveit_configs()
    )

    # Set planning pipeline parameters
    '''moveit_config.planning_pipelines["ompl"]["myrobot_arm"][
        "enforce_constrained_state_space"
    ] = False
    moveit_config.planning_pipelines["ompl"]["myrobot_arm"][
        "projection_evaluator"
    ] = "joints(base_link1_joint,link1_link2_joint)"
    moveit_config.planning_pipelines["ompl"]["myrobot_arm_hand"][
        "enforce_constrained_state_space"
    ] = False
    moveit_config.planning_pipelines["ompl"]["myrobot_arm_hand"][
        "projection_evaluator"
    ] = "joints(base_link1_joint,link1_link2_joint)"
    '''
    # Start the actual move_group node/action server
    run_move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[moveit_config.to_dict()],
    )

    # Demo OMPL constrained planning node
    demo_node = Node(
        package="myrobot_ompl_constrained_planning",
        executable="ompl_constrained_planning",
        output="both",
        parameters=[
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
            moveit_config.robot_description_kinematics,
        ],
    )

    # RViz
    rviz_config_file = (
        get_package_share_directory("myrobot_ompl_constrained_planning")
        + "/launch/ompl_constrained_planning.rviz"
    )
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        parameters=[
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
        ],
    )

    # Static TF
    static_tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher",
        output="log",
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "world", "arm_base_link"],
    )

    # Publish TF
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="both",
        parameters=[moveit_config.robot_description],
    )

    # ros2_control using FakeSystem as hardware
    ros2_controllers_path = os.path.join(
        get_package_share_directory("myrobot_moveit_config"),
        "config",
        "ros2_controllers.yaml",
    )
    ros2_control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[moveit_config.robot_description, ros2_controllers_path],
        output="both",
    )

    # Load controllers
    load_controllers = []
    for controller in [
        "myrobot_arm_controller",
        "myrobot_hand_controller",
        "joint_state_broadcaster",
    ]:
        load_controllers += [
            ExecuteProcess(
                cmd=["ros2 run controller_manager spawner {}".format(controller)],
                shell=True,
                output="screen",
            )
        ]

    return LaunchDescription(
        [
            static_tf,
            robot_state_publisher,
            rviz_node,
            run_move_group_node,
            demo_node,
            ros2_control_node,
        ]
        + load_controllers
    )
