from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_pybullet_package',
            executable='pybullet_node',
            name='pybullet_node',
            output='screen',
        ),
    ])