from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, LaunchConfiguration
import os

def generate_launch_description():
    # Path to the MoveIt launch file
    moveit_launch_file = os.path.join(
        get_package_share_directory('dragon_moveit_config'),
        'launch',
        'demo.launch.py'
    )

    # Create launch description
    ld = LaunchDescription()

    # Include the MoveIt demo launch
    moveit_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(moveit_launch_file)
    )

    # Node for servo_client_client
    servo_client_client_node = Node(
        package='my_robot_first_servo_control',
        executable='servo_client_client',
        output='screen',
    )

    # Node for servo_client
    servo_client_node = Node(
        package='my_robot_first_servo_control',
        executable='servo_client',
        output='screen',
    )

    # Add nodes to the launch description
    ld.add_action(moveit_launch)
    ld.add_action(servo_client_client_node)
    ld.add_action(servo_client_node)

    return ld