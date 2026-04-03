#!/bin/bash

cd ./catkin_lidar_slam_3d

source devel/setup.bash

roslaunch start start_patrol.launch map_name:=my_map_name
