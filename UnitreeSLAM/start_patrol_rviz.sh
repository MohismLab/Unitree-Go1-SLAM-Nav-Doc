#!/bin/bash

cd ./catkin_lidar_slam_3d

source devel/setup.bash

rosrun rviz rviz -d src/lidar_slam_3d/start/rviz/start_patrol.rviz 
