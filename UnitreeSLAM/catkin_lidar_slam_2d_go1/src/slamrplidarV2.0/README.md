# slamrplidarV2.0

<!-- TOC -->

- [slamrplidarV2.0](#slamrplidarv20)
  - [SLAM与运动程序SDK的版本对应关系](#slam与运动程序sdk的版本对应关系)
  - [Version History](#version-history)
    - [2022.01.19: v2.0.0](#20220119-v200)
    - [2022.01.20: v2.0.1](#20220120-v201)
    - [2022.03.02: v2.0.2](#20220302-v202)

<!-- /TOC -->

## SLAM与运动程序SDK的版本对应关系
|SLAM版本| 支持的SDK版本|
|---|---|
|2.0.0| v3.4.2|
|2.0.1| v20220117|
|2.0.2| v20220117|

## Version History
### 2022.01.19: v2.0.0
- 更新`Go1`运动程序SDK版本到`unitree_legged_sdk-v3.4.2`。
  
### 2022.01.20: v2.0.1
- 更新`Go1`运动程序SDK版本到`unitree_legged_sdk-v20220117`。

### 2022.03.02: v2.0.2
- 修改了`startUp.sh`文件，解决了雷达程序杀死视觉程序的问题。
- 将激光雷带启动时的sleep时长从45秒增加到90秒。