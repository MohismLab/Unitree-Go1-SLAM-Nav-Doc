# lidar_slam_3d
- [lidar_slam_3d](#lidar_slam_3d)
  - [1. Author Information](#1-author-information)
  - [2. Version History](#2-version-history)
    - [2022.01.19: v2.0.0](#20220119-v200)
    - [2022.01.20: v2.0.1](#20220120-v201)
    - [2022.02.16: v2.0.2](#20220216-v202)
    - [2022.02.28: v2.0.3](#20220228-v203)
    - [2022.06.20: v2.0.4](#20220620-v204)
    - [2022.06.29: v2.0.5](#20220629-v205)
    - [2022.06.30: v2.0.6](#20220630-v206)
    - [2022.07.06: v2.1.0](#20220706-v210)
    - [2022.07.07: v2.1.1](#20220707-v211)
    - [2022.07.14: v2.1.2](#20220714-v212)
    - [2022.07.23: v2.1.3](#20220723-v213)
    - [2022.08.19: v2.1.4](#20220819-v214)
    - [2022.09.23: v2.1.5](#20220923-v215)
    - [2022.09.26: v2.1.6](#20220926-v216)
    - [2022.10.31](#20221031)
    - [2022.11.03](#20221103)
    - [2022.11.04](#20221104)
    - [2022.11.05](#20221105)
  - [3. User Manual](#3-user-manual)

## 1. Author Information
- Author: Lingbo Meng
- Corporation: Unitree Robotics Ltd.

## 2. Version History
The update history is as follows.

### 2022.01.19: v2.0.0
- For use in `Go1` robot.
- Updtated the motion sdk to `unitree_legged_sdk-v3.4.2`

### 2022.01.20: v2.0.1
- For use in `Go1` robot.
- Updtated the motion sdk to `unitree_legged_sdk-v20220117`

### 2022.02.16: v2.0.2
- For use in `Go1` robot.
- Change to support the lidar hardware of `RS-LiDAR-16`.
- The `Velodyne-VLP16` lidar can not be used directly since this version, and some changes are needed to run with `Velodyne-VLP16` again.

### 2022.02.28: v2.0.3
- For use in `Aliengo` robot.
- Updated to support `aliego_sdk_1.0.17`

### 2022.06.20: v2.0.4
- For use in `B1` robot
- Add support of unitree_legged_sdk for B1 robot - `b1_sdk_v20220616`

### 2022.06.29: v2.0.5
- For use in `Aliengo` + `Velodyne16`.
- Added support of `unitree_legged_sdk` in motion_mode.
- Optimized launch and robot config files in `start` package.
- Added support of `velodyne-16` lidar and `rslidar-16` simultaneously.

### 2022.06.30: v2.0.6
- For use in `A1` + `Velodyne16`

### 2022.07.06: v2.1.0
- For use in `A1` + `RSLIDAR16`
- Updated `LIOSAM` to fuse lidar odometry and robot body odometry, which achieved high-accracy of localization.
- Calibrated finely of ROS navigation parameters, such as `move_base` and `teb_local_planner`

### 2022.07.07: v2.1.1
- For use in `Go1` + `RSLIDAR16`

### 2022.07.14: v2.1.2
- For use in `Go1` + `RS-HELIOS-16P`

### 2022.07.23: v2.1.3
- For use in `B1` + `RSLIDAR16`

### 2022.08.19: v2.1.4
- For use in `A1` + `Velodyne16`

### 2022.09.23: v2.1.5
- For use in `Aliengo` + `RSLIDAR16`

### 2022.09.26: v2.1.6
- For use in `Go1` + `RSLIDAR16`

### 2022.10.31
- For use in `B1` + `RSLIDAR16`
- Updated B1 SDK to `b1_sdk_v20221028`

### 2022.11.03
- For use in `Go1` + `RSLIDAR16`
- Modified quaternion order from `[x,y,z,w]` to `[w,x,y,z]` in `a2_ros2udp`

### 2022.11.04
- For use in `Go1` + `RS-HELIOS-16P`
- Modified quaternion order from `[x,y,z,w]` to `[w,x,y,z]` in `a2_ros2udp`

### 2022.11.05
- For use in `Go1` + `RS-HELIOS-16P`
- In function `publishRobotIMU()` of package `a2_ros2udp`, we discarded using quaterions and started to use RPY euler angles instead, since the quaternion order changed unexpectedly.

## 3. User Manual
For now, there is only the Chinese version of User Mannual:
- [3D激光SLAM开发指南](./user_manual/3D激光SLAM开发指南.md)

For directly running, you can jump to here:
- [3D激光SLAM开发指南](./user_manual/3D激光SLAM开发指南.md#运行)
