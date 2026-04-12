import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    pkg_name = 'rover_control'
    pkg_share = get_package_share_directory(pkg_name)

    # Absolute path to the world file
    world_file = os.path.join(
        pkg_share,
        'worlds',
        'shaastra_arena.world'
    )

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('gazebo_ros'),
                    'launch',
                    'gzserver.launch.py'
                )
            ),
            launch_arguments={
                'world': world_file,
                'verbose': 'true'
            }.items()
        )
    ])
