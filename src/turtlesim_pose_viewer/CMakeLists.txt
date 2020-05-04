cmake_minimum_required(VERSION 2.8.3)
project(turtlesim_pose_viewer)


find_package(catkin REQUIRED COMPONENTS
message_generation
roscpp
rospy
std_msgs
) 

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
CATKIN_DEPENDS
message_runtime)

include_directories(
include ${catkin_INCLUDE_DIRS})

add_executable(topic_subscriber src/turtlesim_pose_subscriber.cpp)
add_dependencies(topic_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(topic_subscriber ${catkin_LIBRARIES})

