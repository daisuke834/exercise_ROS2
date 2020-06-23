#!/bin/bash

project_root=$(cd $(dirname "$0"); pwd)
echo $project_root
cd $project_root

source install/setup.bash
colcon build --packages-select hello_world

ros2 run hello_world my_publisher
#ros2 launch hello_world hello_world.launch.py
