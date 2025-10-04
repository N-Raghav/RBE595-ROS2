from setuptools import find_packages
from setuptools import setup

setup(
    name='franka_control',
    version='0.0.0',
    packages=find_packages(
        include=('franka_control', 'franka_control.*')),
)
