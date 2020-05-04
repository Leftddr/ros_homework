cmake_minimum_required(VERSION 2.8.3)
project(random_number_generator)

find_package(catkin REQUIRED COMPONENTS
message_generation
roscpp
std_msgs
)

add_message_files(FILES rn.msg)

generate_messages(DEPENDENCIES std_msgs)


catkin_package(
#  INCLUDE_DIRS include
 LIBRARIES random_number_generator
 CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
include ${catkin_INCLUDE_DIRS}
)

add_executable(rn_publisher src/rn_pub.cpp)
add_dependencies(rn_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(rn_publisher ${catkin_LIBRARIES})

add_executable(rn_subscriber src/rn_sub.cpp)
add_dependencies(rn_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(rn_subscriber ${catkin_LIBRARIES})


