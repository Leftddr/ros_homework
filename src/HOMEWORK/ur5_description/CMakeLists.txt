cmake_minimum_required(VERSION 2.8.3)
project(ur5_description)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
roscpp
message_generation)

catkin_package(
CATKIN_DEPENDS
)

include_directories(
include ${catkin_INCLUDE_DIRS}
)

add_executable(tf_mat_example src/tf_mat_example.cpp)
add_dependencies(tf_mat_example ${${PROJECT_NAME}_EXPORTED_TARGETS}${catkin_EXPORTED_TARGETS})
target_link_libraries(tf_mat_example ${catkin_LIBRARIES})

