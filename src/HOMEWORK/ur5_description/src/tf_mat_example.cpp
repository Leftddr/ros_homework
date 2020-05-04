#include <ros/ros.h>
#include <vector>
#include <Eigen/Dense>
#include <math.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#define N_JOINT 6

std::vector<double> map_s;
static constexpr double a_dh[N_JOINT] = {0.00000, -0.42500, -0.39225, 0.0000, 0.0000, 0.0000};
static constexpr double d_dh[N_JOINT] = {0.089159, 0.00000, 0.00000, 0.10915, 0.09465, 0.0823};
static constexpr double alpha_dh[N_JOINT] = {1.570796327, 0, 0, 1.570796327, -1.570796327, 0};

using namespace Eigen;
using namespace std;

MatrixXd joint1_1;
MatrixXd joint2_1;
MatrixXd joint3_1;
MatrixXd joint4_1;
MatrixXd joint5_1;
MatrixXd joint6_1;

void calculate(const sensor_msgs::JointState::ConstPtr& ptr){
std::vector<double> map_s;
map_s=ptr->position;
joint1_1 << cos(map_s[0]),-sin(map_s[0]),0,0,
sin(map_s[0]), cos(map_s[0]),0,0,
0,0,1,0,
0,0,0,0;
joint2_1 << cos(map_s[1]),-sin(map_s[1]),0,0,
sin(map_s[1]), cos(map_s[1]),0,0,
0,0,1,0,
0,0,0,0;
joint3_1 << cos(map_s[2]),-sin(map_s[2]),0,0,
sin(map_s[2]), cos(map_s[2]),0,0,
0,0,1,0,
0,0,0,0;
joint4_1 << cos(map_s[3]),-sin(map_s[3]),0,0,
sin(map_s[3]), cos(map_s[3]),0,0,
0,0,1,0,
0,0,0,0;
joint5_1 << cos(map_s[4]),-sin(map_s[4]),0,0,
sin(map_s[4]), cos(map_s[4]),0,0,
0,0,1,0,
0,0,0,0;
joint6_1 << cos(map_s[5]),-sin(map_s[5]),0,0,
sin(map_s[5]), cos(map_s[5]),0,0,
0,0,1,0,
0,0,0,0;
}


int main(int argc, char *argv[]){
ros::init(argc, argv, "tf_mat_example");
ros::NodeHandle nh;
joint1_1.resize(4,4);
joint2_1.resize(4,4);
joint3_1.resize(4,4);
joint4_1.resize(4,4);
joint5_1.resize(4,4);
joint6_1.resize(4,4);

ros::Rate loop_rate(10);
ros::Subscriber sub=nh.subscribe("joint_states",1000,calculate);

MatrixXd joint1_2(4,4);
joint1_2<<1,0,0,0,
0,1,0,0,
0,0,0,d_dh[0],
0,0,0,1;

MatrixXd joint1_3(4,4);
joint1_3<<1,0,0,a_dh[0],
0,1,0,0,
0,0,0,0,
0,0,0,1;

MatrixXd joint1_4(4,4);
joint1_4<<1,0,0,0,
0,cos(alpha_dh[0]),-sin(alpha_dh[0]),0,
0,sin(alpha_dh[0]),cos(alpha_dh[0]),0,
0,0,0,1;

MatrixXd joint2_2(4,4);
joint2_2<<1,0,0,0,
0,1,0,0,
0,0,0,d_dh[1],
0,0,0,1;

MatrixXd joint2_3(4,4);
joint2_3<<1,0,0,a_dh[1],
0,1,0,0,
0,0,0,0,
0,0,0,1;

MatrixXd joint2_4(4,4);
joint2_4<<1,0,0,0,
0,cos(alpha_dh[1]),-sin(alpha_dh[1]),0,
0,sin(alpha_dh[1]),cos(alpha_dh[1]),0,
0,0,0,1;

MatrixXd joint3_2(4,4);

joint3_2<<1,0,0,0,
0,1,0,0,
0,0,0,d_dh[2],
0,0,0,1;

MatrixXd joint3_3(4,4);
joint3_3<<1,0,0,a_dh[2],
0,1,0,0,
0,0,0,0,
0,0,0,1;

MatrixXd joint3_4(4,4);
joint3_4<<1,0,0,0,
0,cos(alpha_dh[2]),-sin(alpha_dh[2]),0,
0,sin(alpha_dh[2]),cos(alpha_dh[2]),0,
0,0,0,1;

MatrixXd joint4_2(4,4);
joint4_2<<1,0,0,0,
0,1,0,0,
0,0,0,d_dh[3],
0,0,0,1;

MatrixXd joint4_3(4,4);
joint4_3<<1,0,0,a_dh[3],
0,1,0,0,
0,0,0,0,
0,0,0,1;

MatrixXd joint4_4(4,4);
joint4_4<<1,0,0,0,
0,cos(alpha_dh[3]),-sin(alpha_dh[3]),0,
0,sin(alpha_dh[3]),cos(alpha_dh[3]),0,
0,0,0,1;

MatrixXd joint5_2(4,4);
joint5_2<<1,0,0,0,
0,1,0,0,
0,0,0,d_dh[4],
0,0,0,1;

MatrixXd joint5_3(4,4);
joint5_3<<1,0,0,a_dh[4],
0,1,0,0,
0,0,0,0,
0,0,0,1;

MatrixXd joint5_4(4,4);
joint5_4<<1,0,0,0,
0,cos(alpha_dh[4]),-sin(alpha_dh[4]),0,
0,sin(alpha_dh[4]),cos(alpha_dh[4]),0,
0,0,0,1;

MatrixXd joint6_2(4,4);
joint6_2<<1,0,0,0,
0,1,0,0,
0,0,0,d_dh[5],
0,0,0,1;

MatrixXd joint6_3(4,4);
joint6_3<<1,0,0,a_dh[5],
0,1,0,0,
0,0,0,0,
0,0,0,1;

MatrixXd joint6_4(4,4);
joint6_4<<1,0,0,0,
0,cos(alpha_dh[5]),-sin(alpha_dh[5]),0,
0,sin(alpha_dh[5]),cos(alpha_dh[5]),0,
0,0,0,1;

MatrixXd A(4,4);
MatrixXd B(4,4);
MatrixXd C(4,4);
MatrixXd D(4,4);
MatrixXd E(4,4);
MatrixXd F(4,4);
MatrixXd result(4,4);

A=joint1_1*joint1_2*joint1_3*joint1_4;
B=joint2_1*joint2_2*joint2_3*joint2_4;
C=joint3_1*joint3_2*joint3_3*joint3_4;
D=joint4_1*joint4_2*joint4_3*joint4_4;
E=joint5_1*joint5_2*joint5_3*joint5_4;
F=joint6_1*joint6_2*joint6_3*joint6_4;

result=A*B*C*D*E*F;

std::cout<<A<<std::endl;
std::cout<<B<<std::endl;
std::cout<<C<<std::endl;
std::cout<<D<<std::endl;
std::cout<<E<<std::endl;
std::cout<<F<<std::endl;
std::cout << result <<std::endl;
ros::spin();
}















