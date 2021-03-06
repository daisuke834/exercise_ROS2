from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='hello_world', node_executable='my_publisher',
            output='screen'),
        launch_ros.actions.Node(
            package='hello_world', node_executable='my_subscriber',
            output='screen')
    ])
