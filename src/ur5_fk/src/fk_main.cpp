#include <ros/ros.h>
#include <vector>
#include <Eigen/Dense>
#include <math.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#define N_JOINT 6
using namespace Eigen;
using namespace std;

static double a_dh[N_JOINT] = {0.00000, -0.42500, -0.39225, 0.0000, 0.0000, 0.0000};
static double d_dh[N_JOINT] = {0.089159, 0.00000, 0.00000, 0.10915, 0.09465, 0.0823};
static double alpha_dh[N_JOINT] = {1.570796327, 0, 0, 1.570796327, -1.570796327, 0};

void callback(const sensor_msgs::JointState::ConstPtr& ptr){
    std::vector<double> theta;
    theta=ptr->position;

    Matrix4d m1_1;
    Matrix4d m1_2;
    Matrix4d m1_3;
    Matrix4d m1_4;
    m1_2 << 1,0,0,0,
    0,1,0,0,
    0,0,1,d_dh[0],
    0,0,0,1;
    m1_3<<1,0,0,a_dh[0],
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    m1_4<<1,0,0,0,
    0,cos(alpha_dh[0]),-sin(alpha_dh[0]),0,
    0,sin(alpha_dh[0]),cos(alpha_dh[0]),0,
    0,0,0,1;

    Matrix4d m2_1;
    Matrix4d m2_2;
    Matrix4d m2_3;
    Matrix4d m2_4;
    m2_2 << 1,0,0,0,
    0,1,0,0,
    0,0,1,d_dh[1],
    0,0,0,1;
    m2_3<<1,0,0,a_dh[1],
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    m2_4<<1,0,0,0,
    0,cos(alpha_dh[1]),-sin(alpha_dh[1]),0,
    0,sin(alpha_dh[1]),cos(alpha_dh[1]),0,
    0,0,0,1;

    Matrix4d m3_1;
    Matrix4d m3_2;
    Matrix4d m3_3;
    Matrix4d m3_4;
    m3_2 << 1,0,0,0,
    0,1,0,0,
    0,0,1,d_dh[2],
    0,0,0,1;
    m3_3<<1,0,0,a_dh[2],
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    m3_4<<1,0,0,0,
    0,cos(alpha_dh[2]),-sin(alpha_dh[2]),0,
    0,sin(alpha_dh[2]),cos(alpha_dh[2]),0,
    0,0,0,1;

    Matrix4d m4_1;
    Matrix4d m4_2;
    Matrix4d m4_3;
    Matrix4d m4_4;
    m4_2 << 1,0,0,0,
    0,1,0,0,
    0,0,1,d_dh[3],
    0,0,0,1;
    m4_3<<1,0,0,a_dh[3],
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    m4_4<<1,0,0,0,
    0,cos(alpha_dh[3]),-sin(alpha_dh[3]),0,
    0,sin(alpha_dh[3]),cos(alpha_dh[3]),0,
    0,0,0,1;

    Matrix4d m5_1;
    Matrix4d m5_2;
    Matrix4d m5_3;
    Matrix4d m5_4;
    m5_2 << 1,0,0,0,
    0,1,0,0,
    0,0,1,d_dh[4],
    0,0,0,1;
    m5_3<<1,0,0,a_dh[4],
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    m5_4<<1,0,0,0,
    0,cos(alpha_dh[4]),-sin(alpha_dh[4]),0,
    0,sin(alpha_dh[4]),cos(alpha_dh[4]),0,
    0,0,0,1;

    Matrix4d m6_1;
    Matrix4d m6_2;
    Matrix4d m6_3;
    Matrix4d m6_4;
    m6_2 << 1,0,0,0,
    0,1,0,0,
    0,0,1,d_dh[5],
    0,0,0,1;
    m6_3<<1,0,0,a_dh[5],
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    m6_4<<1,0,0,0,
    0,cos(alpha_dh[5]),-sin(alpha_dh[5]),0,
    0,sin(alpha_dh[5]),cos(alpha_dh[5]),0,
    0,0,0,1;

    m1_1 << cos(theta[0]),-sin(theta[0]),0,0,
    sin(theta[0]), cos(theta[0]),0,0,
    0,0,1,0,
    0,0,0,1;

    m2_1 << cos(theta[1]),-sin(theta[1]),0,0,
    sin(theta[1]), cos(theta[1]),0,0,
    0,0,1,0,
    0,0,0,1;

    m3_1 << cos(theta[2]),-sin(theta[2]),0,0,
    sin(theta[2]), cos(theta[2]),0,0,
    0,0,1,0,
    0,0,0,1;

    m4_1 << cos(theta[3]),-sin(theta[3]),0,0,
    sin(theta[3]), cos(theta[3]),0,0,
    0,0,1,0,
    0,0,0,1;

    m5_1 << cos(theta[4]),-sin(theta[4]),0,0,
    sin(theta[4]), cos(theta[4]),0,0,
    0,0,1,0,
    0,0,0,1;

    m6_1 << cos(theta[5]),-sin(theta[5]),0,0,
    sin(theta[5]), cos(theta[5]),0,0,
    0,0,1,0,
    0,0,0,1;

    Matrix4d joint1;
    Matrix4d joint2;
    Matrix4d joint3;
    Matrix4d joint4;
    Matrix4d joint5;
    Matrix4d joint6;
    Matrix4d result;
    
    joint1=m1_1*m1_2*m1_3*m1_4;
    joint2=m2_1*m2_2*m2_3*m2_4;
    joint3=m3_1*m3_2*m3_3*m3_4;
    joint4=m4_1*m4_2*m4_3*m4_4;
    joint5=m5_1*m5_2*m5_3*m5_4;
    joint6=m6_1*m6_2*m6_3*m6_4;

 result=joint1*joint2*joint3*joint4*joint5*joint6;

 cout<<result;
}

int main(int argc, char *argv[]){
ros::init(argc, argv, "fk_main");
ros::NodeHandle nh;

ros::Rate loop_rate(10);
ros::Subscriber sub = nh.subscribe("joint_states",1000,callback);
ros::spin();
return 0;
}