import os
from launch import LaunchDescription
from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_demo_launch
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory

def generate_launch_description():
    # Build MoveIt configuration
    moveit_config = MoveItConfigsBuilder("my_robot", package_name="myrobot_moveit_config").to_moveit_configs()
    
    # Define the path to your kinematics.yaml file
    kinematics_yaml_path = os.path.join(
        get_package_share_directory('myrobot_moveit_config'),
        'config',
        'kinematics.yaml'
    )
    
    # Define the MoveIt node
    move_group_node = Node(
        package='moveit_ros_move_group',
        executable='move_group',
        name='move_group',
        output='screen',
        parameters=[moveit_config.robot_description, kinematics_yaml_path]
    )
    
    # Generate the MoveIt demo launch
    demo_launch = generate_demo_launch(moveit_config)
    
    # Return the combined LaunchDescription
    return LaunchDescription([
        move_group_node,
        *demo_launch.entities  # Adding all entities from the demo launch
    ])