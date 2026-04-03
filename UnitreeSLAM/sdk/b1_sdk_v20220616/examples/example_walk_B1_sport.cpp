/************************************************************************
Copyright (c) 2020, Unitree Robotics.Co.Ltd. All rights reserved.
Use of this source code is governed by the MPL-2.0 license, see LICENSE.
************************************************************************/

#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace UNITREE_LEGGED_SDK;

// high cmd
constexpr uint16_t TARGET_PORT = 8082;
constexpr uint16_t LOCAL_PORT = 8081;
constexpr char TARGET_IP[] = "192.168.123.220";   // target IP address


//// low cmd
//constexpr uint16_t TARGET_PORT = 8007;
//constexpr uint16_t LOCAL_PORT = 8082;
//constexpr char TARGET_IP[] = "192.168.123.10";   // target IP address

class Custom
{
public:
    Custom(uint8_t level): safe(LeggedType::B1),
        udp(LOCAL_PORT, TARGET_IP,TARGET_PORT, sizeof(HighCmd), sizeof(HighState))
    {
        udp.InitCmdData(cmd);
    }
    void UDPRecv();
    void UDPSend();
    void RobotControl();

    Safety safe;
    UDP udp;
    HighCmd cmd = {0};
    HighState state = {0};
    int motiontime = 0;
    float dt = 0.002;     // 0.001~0.01
};

void Custom::UDPRecv()
{
    udp.Recv();
}

void Custom::UDPSend()
{  
    udp.Send();
}

void Custom::RobotControl() 
{
    motiontime += 2;
    udp.GetRecv(state);

//        std::cout<<"imu "<<state.imu.accelerometer[0]<<" "
//                <<state.imu.accelerometer[1]<<" "
//               <<state.imu.accelerometer[2]<<std::endl;
//        std::cout<<"imu "<<state.imu.gyroscope[0]<<" "
//                <<state.imu.gyroscope[1]<<" "
//               <<state.imu.gyroscope[2]<<std::endl;
//        std::cout<<"imu "<<state.imu.rpy[0]<<" "
//                <<state.imu.rpy[1]<<" "
//               <<state.imu.rpy[2]<<std::endl;

//        std::cout<<"imu "<<state.imu.quaternion[0]<<" "
//                <<state.imu.quaternion[1]<<" "
//               <<state.imu.quaternion[2]<<" "
//              <<state.imu.quaternion[3]<<std::endl;
//        std::cout<<"forwardSpeed "<<state.velocity[0]<<std::endl;
//        std::cout<<"sideSpeed "<<state.velocity[1]<<std::endl;
//        std::cout<<"rotateSpeed "<<state.yawSpeed<<std::endl;
//        for (int i =0;i<4;i++)
//            std::cout<<"footPosition2B "<<state.footPosition2Body[i].x<<" "
//                                        <<state.footPosition2Body[i].y<<" "
//                                        <<state.footPosition2Body[i].z<<std::endl;
//        for (int i =0;i<4;i++)
//            std::cout<<"footSpeed2B "<<state.footSpeed2Body[i].x<<" "
//                                     <<state.footSpeed2Body[i].y<<" "
//                                     <<state.footSpeed2Body[i].z<<std::endl;

    cmd.velocity[0] = 0.0f;
    cmd.velocity[1] = 0.0f;
    cmd.position[0] = 0.0f;
    cmd.position[1] = 0.0f;
    cmd.yawSpeed = 0.0f;

    cmd.mode = 0;
    cmd.rpy[0]  = 0;
    cmd.rpy[1] = 0;
    cmd.rpy[2] = 0;
    cmd.gaitType = 0;
    cmd.dBodyHeight = 0;
    cmd.dFootRaiseHeight = 0;

    // make sure of 2m space in front of the robot head before starting this test

    if (motiontime == 2)
    {
        std::cout<<"begin sending commands."<<std::endl;
    }

    if (motiontime>1000 && motiontime <2000)
    {
        cmd.mode = 1;    // mode 1: force stand, control robot orientation and height
        cmd.rpy[0] = 0.7;
    }
    if (motiontime>2000 && motiontime <3000)
    {
        cmd.mode = 1;
        cmd.rpy[0] = 0.;
    }
    if (motiontime>3000 && motiontime <4000)
    {
        cmd.mode = 1;
        cmd.rpy[1] = 0.4;
    }
    if (motiontime>4000 && motiontime <5000)
    {
        cmd.mode = 1;
        cmd.rpy[1] = 0.;
    }
    if (motiontime>5000 && motiontime <6000)
    {
        cmd.mode = 1;
        cmd.rpy[2] = 0.5;
    }
    if (motiontime>6000 && motiontime <7000)
    {
        cmd.mode = 1;
        cmd.rpy[2] = 0;
    }
    if (motiontime>8000 && motiontime <9000)
    {
        cmd.mode = 1;
        cmd.dBodyHeight = 0.05;
    }
    if (motiontime>9000 && motiontime <10000)
    {
        cmd.mode = 1;
        cmd.dBodyHeight = -0.15;
    }
    if (motiontime>10000 && motiontime <11000)
    {
        cmd.mode = 1;
        cmd.dBodyHeight = 0.;
    }
    if (motiontime>11000 && motiontime <13000)
    {
        cmd.mode = 2;    // mode 2: following tareget velocity in body frame
        cmd.gaitType = 0; // trot gait
        cmd.velocity[0] = 0.3;
        cmd.velocity[1] = 0;
        cmd.yawSpeed = 0.0;
    }
    if (motiontime>13000 && motiontime <15000)
    {
        cmd.mode = 2;
        cmd.gaitType = 0;
        cmd.velocity[0] = 0;
        cmd.velocity[1] = 0;
        cmd.yawSpeed = -0.4;
        cmd.dFootRaiseHeight = 0.1; // increase swing height
    }
    if (motiontime> 15000 && motiontime <19000)
    {
        cmd.mode = 2;
        cmd.gaitType = 0;
        cmd.velocity[0] = 0;
        cmd.velocity[1] = 0;
        cmd.yawSpeed = 0.2;
        cmd.dFootRaiseHeight = -0.05;
    }
    if (motiontime> 19000 && motiontime <20000)
    {
        cmd.mode = 1;
    }
    if (motiontime>20000 && motiontime <23000)
    {
        cmd.mode = 2;
        cmd.gaitType = 2; // stairs walking gait
        cmd.velocity[0] = 0.2; // avoid using higher forward speed than 0.4m/s for stair climbing gait
        cmd.velocity[1] = 0.;
        cmd.yawSpeed = 0;
    }
    if (motiontime>23000 && motiontime <26000)
    {
        cmd.mode = 2;
        cmd.gaitType = 2;
        cmd.velocity[0] = -0.1; // avoid using higher backward speed than -0.2m/s for stair climbing gait
        cmd.velocity[1] = 0.;
        cmd.yawSpeed = 0;
    }
    if (motiontime>26000 && motiontime <27000)
    {
        cmd.mode = 1;
    }
    if (motiontime>27000 && motiontime <30000)
    {
        cmd.mode = 2;
        cmd.gaitType = 0;
        cmd.dFootRaiseHeight = 0;
    }
    if (motiontime>30000 && motiontime <32000)
    {
        cmd.mode = 1;
    }
    if (motiontime>32000 && motiontime <34000)
    {
        cmd.mode = 6; // stand up
    }
    if (motiontime>34000 && motiontime <36000)
    {
        cmd.mode = 5; // stand down
    }
    if (motiontime>36000 && motiontime <38000)
    {
        cmd.mode = 7; // damping mode
    }
    if (motiontime>38000 && motiontime <40000)
    {
        cmd.mode = 5; // stand down
    }
    if (motiontime>40000 && motiontime <42000)
    {
        cmd.mode = 6; // stand up
    }

    udp.SetSend(cmd);
}

int main(void) 
{
    std::cout << "Communication level is set to HIGH-level." << std::endl
              << "WARNING: Make sure the robot is standing on the ground." << std::endl
              << "Press Enter to continue..." << std::endl;
    std::cin.ignore();

    Custom custom(HIGHLEVEL);
    InitEnvironment();
    LoopFunc loop_control("control_loop", custom.dt,    boost::bind(&Custom::RobotControl, &custom));
    LoopFunc loop_udpSend("udp_send",     custom.dt, 3, boost::bind(&Custom::UDPSend,      &custom));
    LoopFunc loop_udpRecv("udp_recv",     custom.dt, 3, boost::bind(&Custom::UDPRecv,      &custom));

    loop_udpSend.start();
    loop_udpRecv.start();
    loop_control.start();

    while(1){
        sleep(10);
    };

    return 0;
}
