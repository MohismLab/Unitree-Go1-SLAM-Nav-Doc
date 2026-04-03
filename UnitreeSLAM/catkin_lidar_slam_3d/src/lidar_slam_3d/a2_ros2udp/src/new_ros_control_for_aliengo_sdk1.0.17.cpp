/**
 * @file new_ros_control_for_aliengo_sdk1.0.17.cpp
 * @author Luke Meng (lukelbmeng@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "dog_controller_aliengo.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_control_node");
  ros::NodeHandle nh("~");

  signal(SIGINT, MySigintHandler);

  ROS_INFO("[ROS_CONTROL] Node ros2udp has started.");
  std::cout << "[ROS_CONTROL] Control level is set to HIGH-level." << std::endl;
  std::cout << "[ROS_CONTROL] Make sure the robot is standing on the ground." << std::endl;

  DogController dog_controller(nh, AX_CONTROL_PERIOD, AX_CONTROL_LEVEL, AX_LEG_TYPE,
                AX_LOCAL_PORT, AX_TARGET_IP, AX_TARGET_PORT,
                AX_VEL_CMD_MODE);
  InitEnvironment();

  // Run function Custom::UDPSend() and Custom::UDPRecv in distinct threads
  // LoopFunc loop_udpSend("udp_send", custom.dt_, 3, boost::bind(&Custom::UDPSend, &custom));
  // LoopFunc loop_udpRecv("udp_recv", custom.dt_, 3, boost::bind(&Custom::UDPRecv, &custom));
  // loop_udpSend.start();
  // loop_udpRecv.start();

  // ROS Spin
  ros::Rate loop_rate(1.0 / AX_CONTROL_PERIOD);
  while (nh.ok())
  {
    ros::spinOnce();
    dog_controller.UDPRecv();
    dog_controller.UDPSend();
    dog_controller.savePatrolPoints();
    loop_rate.sleep();
  }

  return 0;
}
