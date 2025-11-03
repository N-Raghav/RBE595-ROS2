from setuptools import find_packages
from setuptools import setup

setup(
    name='camera_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('camera_interfaces', 'camera_interfaces.*')),
)
