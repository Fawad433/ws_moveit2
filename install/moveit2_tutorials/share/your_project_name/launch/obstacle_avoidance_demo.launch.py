from launch import LaunchDescription
from launch_ros.actions import Node, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Include the panda_moveit_config demo.launch.py
    panda_demo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([get_package_share_directory('panda_moveit_config'), '/launch/demo.launch.py'])
    )

    # Play the rosbag that contains the pointcloud data
    point_clouds_node = Node(
        package='moveit_tutorials',
        executable='bag_publisher_maintain_time',
        name='point_clouds',
        output='screen'
    )

    # Broadcast static tf for robot root
    to_panda_tf_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='to_panda',
        arguments=['0', '0', '0', '0', '0', '0', 'world', 'panda_link0'],
        output='screen'
    )

    to_camera_tf_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='to_camera',
        arguments=['0.115', '0.427', '0.570', '0', '0.2', '1.92', 'camera_rgb_optical_frame', 'world'],
        output='screen'
    )

    return LaunchDescription([
        panda_demo_launch,
        point_clouds_node,
        to_panda_tf_node,
        to_camera_tf_node
    ])


#<launch>
#  <include file="$(find panda_moveit_config)/launch/demo.launch" />

#  <!-- Play the rosbag that contains the pointcloud data -->
#  <node pkg="moveit_tutorials" type="bag_publisher_maintain_time" name="point_clouds" />

#  <!-- If needed, broadcast static tf for robot root -->
#  <node pkg="tf2_ros" type="static_transform_publisher" name="to_panda" args="0 0 0 0 0 0  world panda_link0" />
#  <node pkg="tf2_ros" type="static_transform_publisher" name="to_camera" args="0.115 0.427 0.570 0 0.2 1.92 camera_rgb_optical_frame world" />

#</launch>
