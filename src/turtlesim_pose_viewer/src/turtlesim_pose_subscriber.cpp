#include "ros/ros.h"
#include "turtlesim/Pose.h"

void msgCallback(const turtlesim::Pose::ConstPtr& msg){
ROS_INFO("receive x =%f", msg->x);
ROS_INFO("receive y =%f", msg->y);
ROS_INFO("receive theta =%f", msg->theta);
ROS_INFO("receive linear_velocity =%f", msg->linear_velocity);
ROS_INFO("receive angular_velocity =%f", msg->angular_velocity);
}

int main(int argc, char**argv){
ros::init(argc,argv,"topic_subscriber");
ros::NodeHandle nh;
ros:: Subscriber turltesim_pose_viewer_sub=nh.subscribe("turtle1/pose",100,msgCallback);
ros::spin();
}




