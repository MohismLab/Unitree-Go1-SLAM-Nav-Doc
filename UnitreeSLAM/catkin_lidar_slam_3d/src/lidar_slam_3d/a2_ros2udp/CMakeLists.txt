cmake_minimum_required(VERSION 3.0.2)
project(a2_ros2udp)

## Compile as C++11
add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS "-O3")

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  std_msgs
  roslib  # for using ros::package

  geometry_msgs
  # controller_manager
)

catkin_package(
  CATKIN_DEPENDS 
  roscpp 
  std_msgs
  roslib
  geometry_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## include and link directory

## test_for_sdk2ros
# include_directories(~/UnitreeSLAM/sdk/unitree_legged_sdk-3.3.1/include)
# link_directories(~/UnitreeSLAM/sdk/unitree_legged_sdk-3.3.1/lib)
# set(EXTRA_LIBS -pthread libunitree_legged_sdk_arm64.so lcm)   # for arm
# add_executable(test_for_sdk2ros src/test_for_sdk2ros.cpp)
# target_link_libraries(test_for_sdk2ros  ${catkin_LIBRARIES} ${EXTRA_LIBS} )

### For A1 NX
# include_directories(../../../../sdk/unitree_legged_sdk-3.3.1/include)
# link_directories(../../../../sdk/unitree_legged_sdk-3.3.1/lib)
# set(EXTRA_LIBS -pthread libunitree_legged_sdk_arm64.so lcm)   # for arm
# add_executable(ros_control src/new_ros_control_for_a1_sdk_3_3_1.cpp)
# target_link_libraries(ros_control  ${catkin_LIBRARIES} ${EXTRA_LIBS} )

### For Go1 NX
include_directories(../../../../sdk/unitree_legged_sdk-v20220117/include)
link_directories(../../../../sdk/unitree_legged_sdk-v20220117/lib)
set(EXTRA_LIBS -pthread libunitree_legged_sdk_arm64.so lcm)   # for arm
add_executable(ros_control src/new_ros_control_for_go1_sdk_20220117.cpp)
target_link_libraries(ros_control  ${catkin_LIBRARIES} ${EXTRA_LIBS})

### For Aliengo x86: 192.168.123.220
# include_directories(../../../../sdk/aliengo_sdk_v1.0.17/include)
# link_directories(../../../../sdk/aliengo_sdk_v1.0.17/lib)
# set(EXTRA_LIBS -pthread libunitree_legged_sdk.so lcm)
# add_executable(ros_control src/new_ros_control_for_aliengo_sdk1.0.17.cpp)
# target_link_libraries(ros_control  ${catkin_LIBRARIES} ${EXTRA_LIBS} ${OpenCV_LIBS})

### For B1 in NX: 192.168.123.24
# include_directories(../../../../sdk/b1_sdk_v20221028/include)
# link_directories(../../../../sdk/b1_sdk_v20221028/lib/cpp/arm64)
# set(EXTRA_LIBS -pthread libunitree_legged_sdk.so lcm)
# add_executable(ros_control src/new_ros_control_for_b1_sdk_20220723.cpp)
# target_link_libraries(ros_control  ${catkin_LIBRARIES} ${EXTRA_LIBS} ${OpenCV_LIBS})