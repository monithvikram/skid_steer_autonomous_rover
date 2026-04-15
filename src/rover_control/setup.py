import os
from glob import glob
from setuptools import setup

package_name = 'rover_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),

        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.xml')),
        (os.path.join('share', package_name, 'urdf'),
         glob('urdf/*.urdf') + glob('urdf/*.xacro')),
        (os.path.join('share', package_name, 'worlds'), glob('worlds/*.world')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
        (os.path.join('share', package_name, 'rviz'), glob('rviz/*.rviz')),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='monith',
    maintainer_email='monith@todo.todo',
    description='Rover Control Package',
    license='TODO',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'nav_node_based_on_ddc_odom = rover_control.nav_node_rely_on_ddc_odom:main',
            'sim_nav_node = rover_control.sim_nav_node:main',

            'teleop_to_pwm = rover_control.teleop_to_pwm:main',
            'pwm_to_odom = rover_control.pwm_to_odom_estimator:main',

            'waypoint_server = rover_control.waypoint_server:main',
            'waypoint_client = rover_control.waypoint_client:main',
            'odom_validator = rover_control.odom_validator:main',
            'imu_odom_validator = rover_control.imu_odom_validator:main',
            'flysky_driver = rover_control.flysky_driver:main',
        ],
    },
)
