#include "ros/ros.h"
#include "random_number_generator/rn.h"

int sum=0;
int count=0;

void msgCallback(const random_number_generator::rn::ConstPtr& msg){
sum+=msg->randint;
ROS_INFO("COUNT = %d",count++);
ROS_INFO("receieve limit = %d", msg->limit);
ROS_INFO("receieve randint = %d", msg->randint);
ROS_INFO("Total = %d",sum);
}

int main(int argc, char**argv){
ros::init(argc,argv, "rn_subscriber");
ros::NodeHandle nh;
ros::Subscriber random_number_generator_sub=nh.subscribe("random_number_generator",100,msgCallback);

ros::spin();
}
