from setuptools import find_packages, setup

package_name = 'my_robot_first_servo_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robot',
    maintainer_email='fawadahmed433@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "servo_client = my_robot_first_servo_control.servo_client_node:main",
            "servo_client_client = my_robot_first_servo_control.servo_client_node_client:main"
        ],
    },
)
