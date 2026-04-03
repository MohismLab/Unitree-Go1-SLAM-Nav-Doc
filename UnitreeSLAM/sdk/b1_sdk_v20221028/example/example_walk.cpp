/*****************************************************************
 Copyright (c) 2020, Unitree Robotics.Co.Ltd. All rights reserved.
******************************************************************/

#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace UNITREE_LEGGED_SDK;

class Custom
{
public:
    Custom(uint8_t level) : safe(LeggedType::Go1),
                            udp(level, 8090, "192.168.123.220", 8082)
    {
        udp.InitCmdData(cmd);
        // udp.print = true;
    }
    void UDPRecv();
    void UDPSend();
    void RobotControl();

    Safety safe;
    UDP udp;
    HighCmd cmd = {0};
    HighState state = {0};
    int motiontime = 0;
    float dt = 0.002; // 0.001~0.01
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
    printf("%d   %f\n", motiontime, state.imu.quaternion[2]);

    cmd.mode = 0; // 0:idle, default stand      1:forced stand     2:walk continuously
    cmd.gaitType = 0;
    cmd.speedLevel = 0;
    cmd.footRaiseHeight = 0;
    cmd.bodyHeight = 0;
    cmd.euler[0] = 0;
    cmd.euler[1] = 0;
    cmd.euler[2] = 0;
    cmd.velocity[0] = 0.0f;
    cmd.velocity[1] = 0.0f;
    cmd.yawSpeed = 0.0f;
    cmd.reserve = 0;

    if (motiontime > 0 && motiontime < 1000)
    {
        cmd.mode = 6;
    }
    else if (motiontime >= 1000 && motiontime <= 5000)
    {
        cmd.mode = 1;
        // cmd.stand_com_xy_bias[0] = 0.0;
        // cmd.stand_com_xy_bias[1] = -0.2;
    }
    else if (motiontime >= 5000 && motiontime <= 10000)
    {
        cmd.mode = 2;

        cmd.velocity[0] = 0.3;

        // cmd.stand_foot_xy_bias[0] = 0.2;
        // cmd.stand_foot_xy_bias[1] = 0.2;
    }
    else
    {
        cmd.mode = 1;
    }

    // if (motiontime > 0 && motiontime <= 1000)
    // {
    //     cmd.mode = 6;
    // }
    // else if (motiontime >= 1000 && motiontime <= 6000)
    // {
    //     cmd.mode = 1;
    //     cmd.stand_com_xy_bias[0] = 0.2;
    //     cmd.stand_com_xy_bias[1] = 0.0;
    // }
    // else if (motiontime >= 6000 && motiontime <= 11000)
    // {
    //     cmd.mode = 1;
    //     cmd.stand_com_xy_bias[0] = -0.2;
    //     cmd.stand_com_xy_bias[1] = 0.0;
    // }
    // else if (motiontime >= 11000 && motiontime <= 16000)
    // {
    //     cmd.mode = 1;
    //     cmd.stand_com_xy_bias[0] = 0.0;
    //     cmd.stand_com_xy_bias[1] = 0.2;
    // }
    // else if (motiontime >= 16000 && motiontime <= 21000)
    // {
    //     cmd.mode = 1;
    //     cmd.stand_com_xy_bias[0] = 0.0;
    //     cmd.stand_com_xy_bias[1] = -0.2;
    // }
    // else
    // {
    //     cmd.mode = 0;
    // }

    // SNStruct sn;
    // memcpy(&sn, &state.SN[0], 8);

    std::cout << "state.mode:\t" << static_cast<int>(state.mode) << "\n\n";
    // printf("gaitType = %d     %d    \n", state.gaitType, cmd.levelFlag);
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
    LoopFunc loop_control("control_loop", custom.dt, boost::bind(&Custom::RobotControl, &custom));
    LoopFunc loop_udpSend("udp_send", custom.dt, 3, boost::bind(&Custom::UDPSend, &custom));
    LoopFunc loop_udpRecv("udp_recv", custom.dt, 3, boost::bind(&Custom::UDPRecv, &custom));

    loop_udpSend.start();
    loop_udpRecv.start();
    loop_control.start();

    while (1)
    {
        sleep(10);
    };

    return 0;
}
