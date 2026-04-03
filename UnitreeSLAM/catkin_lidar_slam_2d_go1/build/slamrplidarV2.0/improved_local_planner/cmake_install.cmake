# Install script for directory: /home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/src/slamrplidarV2.0/improved_local_planner

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/improved_local_planner/msg" TYPE FILE FILES
    "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/src/slamrplidarV2.0/improved_local_planner/msg/TrajectoryPointMsg.msg"
    "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/src/slamrplidarV2.0/improved_local_planner/msg/TrajectoryMsg.msg"
    "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/src/slamrplidarV2.0/improved_local_planner/msg/FeedbackMsg.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/improved_local_planner/cmake" TYPE FILE FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/build/slamrplidarV2.0/improved_local_planner/catkin_generated/installspace/improved_local_planner-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/include/improved_local_planner")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/share/roseus/ros/improved_local_planner")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/share/common-lisp/ros/improved_local_planner")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/share/gennodejs/ros/improved_local_planner")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/lib/python2.7/dist-packages/improved_local_planner")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/lib/python2.7/dist-packages/improved_local_planner")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/improved_local_planner" TYPE FILE FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/include/improved_local_planner/DBLocalPlannerReconfigureConfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/improved_local_planner" TYPE FILE FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/lib/python2.7/dist-packages/improved_local_planner/__init__.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/lib/python2.7/dist-packages/improved_local_planner/cfg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/improved_local_planner" TYPE DIRECTORY FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/devel/lib/python2.7/dist-packages/improved_local_planner/cfg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/build/slamrplidarV2.0/improved_local_planner/catkin_generated/installspace/improved_local_planner.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/improved_local_planner/cmake" TYPE FILE FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/build/slamrplidarV2.0/improved_local_planner/catkin_generated/installspace/improved_local_planner-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/improved_local_planner/cmake" TYPE FILE FILES
    "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/build/slamrplidarV2.0/improved_local_planner/catkin_generated/installspace/improved_local_plannerConfig.cmake"
    "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/build/slamrplidarV2.0/improved_local_planner/catkin_generated/installspace/improved_local_plannerConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/improved_local_planner" TYPE FILE FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/src/slamrplidarV2.0/improved_local_planner/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/improved_local_planner" TYPE FILE FILES "/home/unitree/UnitreeSLAM/catkin_lidar_slam_2d_go1/src/slamrplidarV2.0/improved_local_planner/improved_local_planner_plugin.xml")
endif()

