from setuptools import setup, find_packages

package_name = 'my_pybullet_package'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(),
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', ['config/robotic_arm.urdf'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    entry_points={
        'console_scripts': [
            'pybullet_node = my_pybullet_package.pybullet_node:main',
        ],
    },
)
