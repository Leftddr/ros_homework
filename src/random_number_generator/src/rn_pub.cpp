#include "ros/ros.h"
#include "random_number_generator/rn.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
ros::init(argc,argv,"rn_publisher");
ros::NodeHandle nh;
ros::Publisher random_number_generator_pub=nh.advertise<random_number_generator::rn>("random_number_generator",100);
nh.setParam("limit_method",10);

ros::Rate loop_rate(10);

random_number_generator::rn msg;

while(ros::ok()){
srand(time(NULL));
nh.getParam("limit_method",msg.limit);
msg.randint = rand()% msg.limit;

ROS_INFO("send msg limit = %d", msg.limit);
ROS_INFO("send msg randint =%d",msg.randint);

random_number_generator_pub.publish(msg);

loop_rate.sleep();
}
return 0;
}

