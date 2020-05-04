#include "ros/ros.h"
#include <cmath>
#include <Eigen/Dense>
#define PI 3.14159265
#define radian 180/PI

using namespace Eigen;
int main(int argc, char *argv[]){
ros::init(argc, argv, "tf_mat_example");
double degree = radian;
double degree2 = PI/(2*radian);
MatrixXd m1(4,4);
m1<<1,0,0,0,
0,cos(PI/2),-sin(PI/2),0,
0,sin(PI/2),cos(PI/2),0,
0,0,0,1;
MatrixXd m2(4,4);

m2<<1,0,0,0,
0,1,0,0,
0,0,1,1,
0,0,0,1;

MatrixXd m3(4,4);

m3<<1,0,0,0,
0,1,0,0,
0,0,1,0,
0,0,0,1;

MatrixXd m4(4,4);

m4<<cos(1),-sin(1),0,0,
sin(1),cos(1),0,0,
0,0,1,0,
0,0,0,1;

MatrixXd m_final(4,4);

m_final=m4*m2*m3*m1;

std::cout<<m_final<<std::endl;
}

