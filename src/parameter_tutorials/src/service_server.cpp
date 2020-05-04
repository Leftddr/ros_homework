#include "ros/ros.h"
#include "parameter_tutorials/SrvTutorial.h"

enum {PLUS=1,MINUS,MULTIPLICATION,DIVISION};

class SimpleCalculator{
private:
int g_operator;
ros::NodeHandle nh;
ros::ServiceServer parameter_server;
public:
SimpleCalculator(){
g_operator=PLUS;
nh.setParam("calculation_method",g_operator);
}
void setServiceServer();
bool calculation(parameter_tutorials::SrvTutorial::Request &req, parameter_tutorials::SrvTutorial::Response &res){
nh.getParam("calculation_method",g_operator);
switch(g_operator){
case PLUS:
res.result=req.a+req.b;
break;
case MINUS:
res.result=req.a-req.b;
break;
case MULTIPLICATION:
res.result=req.a*req.b;
break;
case DIVISION:
res.result=req.a/req.b;
break;
default:
ROS_WARN("UNKNOWN OPERATOR TYPE, IT MUST BE 1,2,3,4");
break;
}

ROS_INFO("request : x=%ld, y=%ld",static_cast<long int>(req.a), static_cast<long int>(req.b));
ROS_INFO("sending back response : %ld", static_cast<long int>(res.result));
return true;
}
};

int main(int argc, char *argv[]){
ros::init(argc,argv,"parameter_server");
ros::NodeHandle nh;
SimpleCalculator simple;
simple.setServiceServer();

ROS_INFO("ready srv server");
ros::Rate loop_rate(10);
ROS_INFO("E");
ros::spin();
return 0;
}

void SimpleCalculator::setServiceServer(){
parameter_server=nh.advertiseService("parameter_tutorial",&SimpleCalculator::calculation,this);//클래스에서 이렇게 쓴다. this는 base class pointer형으로 바꾸어 주어 쓴다.
}

