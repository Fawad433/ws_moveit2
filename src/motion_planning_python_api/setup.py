from setuptools import find_packages, setup

package_name = 'motion_planning_python_api'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Add launch, scripts, and config directories
        ('share/' + package_name + '/launch', ['launch/motion_planning_python_api_tutorial.launch.py']),
        ('lib/' + package_name, ['scripts/motion_planning_python_api_tutorial.py',
                                 'scripts/motion_planning_python_api_planning_scene.py']),
        ('share/' + package_name + '/config', ['config/motion_planning_python_api_tutorial.yaml']),
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
            'motion_planning_tutorial = motion_planning_python_api.motion_planning_python_api_tutorial:main',
            'planning_scene_tutorial = motion_planning_python_api.motion_planning_python_api_planning_scene:main',
        ],
    },
)
