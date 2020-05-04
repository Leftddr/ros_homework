cmake_minimum_required(VERSION 2.8.3)
project(mobile_robot)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS roscpp tf)

catkin_package(
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

add_executable(state_publisher
  src/state_publisher.cpp
)
add_dependencies(state_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(state_publisher
  ${catkin_LIBRARIES}
)

add_executable(custom_joint_state_publisher
  src/custom_joint_state_publisher.cpp
)
add_dependencies(custom_joint_state_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(custom_joint_state_publisher
  ${catkin_LIBRARIES}
)

add_executable(custom_odom_tf
  src/custom_odom_tf.cpp
)
add_dependencies(custom_odom_tf ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(custom_odom_tf
  ${catkin_LIBRARIES}
)