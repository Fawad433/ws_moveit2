import os
import yaml
import xacro
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory

def get_package_file(package, file_path):
    """Get the location of a file installed in an ament package"""
    package_path = get_package_share_directory(package)
    absolute_file_path = os.path.join(package_path, file_path)
    return absolute_file_path

def load_file(file_path):
    """Load the contents of a file into a string"""
    try:
        with open(file_path, 'r') as file:
            return file.read()
    except EnvironmentError as e:
        print(f"Error loading file {file_path}: {e}")
        return None

def load_yaml(file_path):
    """Load a yaml file into a dictionary"""
    try:
        with open(file_path, 'r') as file:
            return yaml.safe_load(file)
    except EnvironmentError as e:
        print(f"Error loading YAML file {file_path}: {e}")
        return None

def run_xacro(xacro_file):
    """Run xacro and output a file in the same directory with the same name, w/o a .xacro suffix"""
    urdf_file, ext = os.path.splitext(xacro_file)
    if ext != '.xacro':
        raise RuntimeError(f'Input file to xacro must have a .xacro extension, got {xacro_file}')
    os.system(f'xacro {xacro_file} -o {urdf_file}')
    return urdf_file

def generate_launch_description():
    xacro_file = get_package_file('myrobot_moveit_config', 'config/my_robot.urdf.xacro')
    urdf_file = run_xacro(xacro_file)
    srdf_file = get_package_file('myrobot_moveit_config', 'config/my_robot.srdf')
    kinematics_file = get_package_file('myrobot_moveit_config', 'config/kinematics.yaml')
    # ompl_config_file = get_package_file('myrobot_moveit_config', 'config/ompl_planning.yaml')
    moveit_controllers_file = get_package_file('myrobot_moveit_config', 'config/moveit_controllers.yaml')
    ros_controllers_file = get_package_file('myrobot_moveit_config', 'config/ros2_controllers.yaml')

    robot_description = load_file(urdf_file)
    robot_description_semantic = load_file(srdf_file)
    kinematics_config = load_yaml(kinematics_file)
    # ompl_config = load_yaml(ompl_config_file)

    if robot_description is None:
        raise RuntimeError(f"Failed to load URDF file: {urdf_file}")
    if robot_description_semantic is None:
        raise RuntimeError(f"Failed to load SRDF file: {srdf_file}")
    if kinematics_config is None:
        raise RuntimeError(f"Failed to load kinematics YAML file: {kinematics_file}")
    # if ompl_config is None:
    #     raise RuntimeError(f"Failed to load OMPL config YAML file: {ompl_config_file}")

    moveit_controllers = {
        'moveit_simple_controller_manager': load_yaml(moveit_controllers_file),
        'moveit_controller_manager': 'moveit_simple_controller_manager/MoveItSimpleControllerManager'
    }

    if moveit_controllers['moveit_simple_controller_manager'] is None:
        raise RuntimeError(f"Failed to load MoveIt controllers YAML file: {moveit_controllers_file}")

    trajectory_execution = {
        'moveit_manage_controllers': True,
        'trajectory_execution.allowed_execution_duration_scaling': 1.2,
        'trajectory_execution.allowed_goal_duration_margin': 0.5,
        'trajectory_execution.allowed_start_tolerance': 0.01
    }
    planning_scene_monitor_config = {
        'publish_planning_scene': True,
        'publish_geometry_updates': True,
        'publish_state_updates': True,
        'publish_transforms_updates': True
    }

    # MoveIt node
    move_group_node = Node(
        package='moveit_ros_move_group',
        executable='move_group',
        output='screen',
        parameters=[
            {
                'robot_description': robot_description,
                'robot_description_semantic': robot_description_semantic,
                'robot_description_kinematics': kinematics_config,
            },
            moveit_controllers,
            trajectory_execution,
            planning_scene_monitor_config,
        ],
    )

    # TF information
    robot_state_publisher = Node(
        name='robot_state_publisher',
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[
            {'robot_description': robot_description}
        ]
    )

    # Visualization (parameters needed for MoveIt display plugin)
    rviz = Node(
        name='rviz',
        package='rviz2',
        executable='rviz2',
        output='screen',
        parameters=[
            {
                'robot_description': robot_description,
                'robot_description_semantic': robot_description_semantic,
                'robot_description_kinematics': kinematics_config,
            }
        ],
    )


    print("robot_description:", robot_description)
    print("robot_description_semantic:", robot_description_semantic)
    print("kinematics_config:", kinematics_config)
    print("moveit_controllers:", moveit_controllers)

    # Controller manager for realtime interactions
    ros2_control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[
            {'robot_description': robot_description},
            ros_controllers_file
        ],
        output="screen",
    )

    # Print ros2_control_node parameters
    print("ros2_control_node parameters:", [
        {'robot_description': robot_description},
        ros_controllers_file
    ])

    # Startup up ROS2 controllers (will exit immediately)
    controller_names = ['myrobot_arm_controller', 'joint_state_broadcaster', 'myrobot_hand_controller']
    spawn_controllers = [
        Node(
            package="controller_manager",
            executable="spawner",
            arguments=[controller],
            output="screen")
        for controller in controller_names
    ]
    for controller in controller_names:
        print("Spawning controller:", controller)

    return LaunchDescription([
        move_group_node,
        robot_state_publisher,
        ros2_control_node,
        rviz,
    ] + spawn_controllers)


# This has issue when I plan with RVIZ planning