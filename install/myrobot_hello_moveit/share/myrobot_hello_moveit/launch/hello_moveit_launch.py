from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='myrobot_hello_moveit',
            executable='myrobot_hello_moveit',
            output='screen',
            parameters=[
                {'robot_description': '/home/robot/ws_moveit2/src/moveit_resources/myrobot_moveit_config/config/my_robot.urdf.xacro'},
                {'robot_description_semantic': '/home/robot/ws_moveit2/src/moveit_resources/myrobot_moveit_config/config/my_robot.srdf'},
                {'robot_description_kinematics': '/home/robot/ws_moveit2/src/moveit_resources/myrobot_moveit_config/config/kinematics.yaml'},
            ]
        )
    ])