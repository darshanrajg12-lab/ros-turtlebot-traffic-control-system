#include "ros/ros.h"
#include "turtlebot3_drive.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot3_drive");

  Turtlebot3Drive turtlebot3_drive;

  ros::Rate loop_rate(125);

  while (ros::ok())
  {
    turtlebot3_drive.controlLoop();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}