import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'camera_pkg'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Include all srv files
        (os.path.join('share', package_name, 'srv'), glob('srv/*.srv')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Raghav Nallaperumal',
    maintainer_email='rnallaperumal@wpi.edu',
    description='A ROS 2 service node to capture images from a RealSense camera.',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'camera_service = camera_pkg.camera_node:main',
        ],
    },
)