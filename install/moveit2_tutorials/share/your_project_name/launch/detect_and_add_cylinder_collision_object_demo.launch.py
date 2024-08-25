from launch import LaunchDescription
from launch_ros.actions import Node, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    obstacle_avoidance_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([get_package_share_directory('moveit_tutorials'), '/launch/obstacle_avoidance_demo.launch.py'])
    )

    point_cloud_preprocessor_node = Node(
        package='moveit_tutorials',
        executable='cylinder_segment',
        name='point_cloud_preprocessor',
        output='screen'
    )

    return LaunchDescription([
        obstacle_avoidance_launch,
        point_cloud_preprocessor_node
    ])




#<launch>
#  <include file="$(find moveit_tutorials)/doc/perception_pipeline/launch/obstacle_avoidance_demo.launch" />

#  <!-- Run the detection and adding cylinder node -->
#  <node pkg="moveit_tutorials" type="cylinder_segment" name="point_cloud_preprocessor" />

#</launch>
