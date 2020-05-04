#include <string>
#include <ros/ros.h>
#include <gazebo_msgs/LinkStates.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <vector>
#include <math.h>

using namespace std;

class DiffDriveOdometry{
private:
    float x;
    float y;
    float theta;
    float seq;
    float right_wheel_velocity;
    float left_wheel_velocity;

    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Publisher odom_pub;
    ros::Time last;

    std::vector<std::string> name;
    std::string leftwheel_linkname;
    std::string rightwheel_linkname;
    std::string odom_link_id;
    std::string base_link_id;
    float separation_length=0;
    int lwheel=0;
    int rwheel=0;
    tf::TransformBroadcaster br;
public:
    DiffDriveOdometry(): seq(3), nh(), x(0), y(0), theta(0){
    if(!nh.getParam("mobile_robot_odometry/leftwheel_linkname",leftwheel_linkname)) throw std::runtime_error("set leftwheel_linkname");
    if(!nh.getParam("mobile_robot_odometry/rightwheel_linkname",rightwheel_linkname)) throw std::runtime_error("set rightwheel_linkname");
    if(!nh.getParam("mobile_robot_odometry/odom_link_id",odom_link_id)) throw std::runtime_error("set odom_link_id");
    if(!nh.getParam("mobile_robot_odometry/base_link_id",base_link_id)) throw std::runtime_error("set base_link_id");
    if(!nh.getParam("mobile_robot_odometry/separation_length",separation_length)) throw std::runtime_error("set separation_length");
    sub = nh.subscribe("gazebo/link_states",1000,&DiffDriveOdometry::calcWheeVelocityGazeboCB,this);

    odom_pub=nh.advertise<nav_msgs::Odometry>("custom_odom",50);
    last=ros::Time::now();
    }

    float x_dot;
    float y_dot;
    float theta_dot;
    float angular_velocity;
    float velocity;
    void calcWheeVelocityGazeboCB(const gazebo_msgs::LinkStates::ConstPtr& ptr);
    void broadcastTransform();
};

void DiffDriveOdometry::calcWheeVelocityGazeboCB(const gazebo_msgs::LinkStates::ConstPtr& ptr){
    int i=0;
    name=ptr->name;    
    
    while(1){
        if(name[i].compare(leftwheel_linkname)==0)
        lwheel=i;
        if(name[i].compare(rightwheel_linkname)==0){
        rwheel=i; break;}
        i++;
    }

    right_wheel_velocity=sqrt(ptr->twist[rwheel].linear.x*ptr->twist[rwheel].linear.x+ptr->twist[rwheel].linear.y*ptr->twist[rwheel].linear.y);
    left_wheel_velocity=sqrt(ptr->twist[lwheel].linear.x*ptr->twist[lwheel].linear.x+ptr->twist[lwheel].linear.y*ptr->twist[lwheel].linear.y);
    velocity=(right_wheel_velocity+left_wheel_velocity)/2;
    angular_velocity=(right_wheel_velocity-left_wheel_velocity)/separation_length;
}

void DiffDriveOdometry::broadcastTransform(){
    ros::Time cur = ros::Time::now();
    double dt=(cur-last).toSec();

    theta += angular_velocity * dt;

    x_dot=velocity*cos(theta);
    y_dot=velocity*sin(theta);

    last = cur;

    x+=x_dot*dt;
    y+=y_dot*dt;

    nav_msgs::Odometry odom;
    odom.header.seq = seq++;
    odom.header.stamp = cur;
    odom.header.frame_id = odom_link_id;
    odom.child_frame_id = base_link_id;

    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0;
    odom.pose.pose.orientation = tf::createQuaternionMsgFromYaw(theta);
    odom.twist.twist.linear.x = x_dot;
    odom.twist.twist.linear.y = y_dot;
    odom.twist.twist.angular.z = theta;

    odom_pub.publish(odom);


    tf::Transform transform;
    transform.setOrigin(tf::Vector3(x,y,0.0));
    tf::Quaternion q;
    q.setRPY(0,0,theta);
    transform.setRotation(q);

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), odom_link_id, "base_link" ));
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "mobile_robot_odometry");

    DiffDriveOdometry me;
    ros::Rate loop_rate(10);

    while(ros::ok()){
    me.broadcastTransform();
    loop_rate.sleep();
    ros::spinOnce();
    }
    
    return 0;
}