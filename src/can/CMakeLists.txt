cmake_minimum_required(VERSION 2.8.3)
project(can)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


## Generate messages in the 'msg' folder
add_message_files(
   FILES
   control.msg
   frame.msg
)



## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES can
  CATKIN_DEPENDS message_runtime
#  DEPENDS system_lib
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



#link_directories(${PCL_LIBRARY_DIRS})
add_executable(can_analysis src/can_analysis.cpp)
add_dependencies(can_analysis ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(can_analysis ${catkin_LIBRARIES})

#link_directories(${PCL_LIBRARY_DIRS})
add_executable(can_publisher src/can_publisher.cpp)
add_dependencies(can_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(can_publisher ${catkin_LIBRARIES})

#link_directories(${PCL_LIBRARY_DIRS})
add_executable(can_test src/can_test.cpp)
add_dependencies(can_test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(can_test ${catkin_LIBRARIES})

