cmake_minimum_required(VERSION 2.8.3)
project(camera)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  cv_bridge
  image_transport
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES camera
  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories(/home/zj/CLionProjects/cv2/include)

#add_executable(camera line_dect_opt.cpp )
#TARGET_LINK_LIBRARIES(camera ${OpenCV_LIBS} )#添加链接库

add_executable(image_pub src/image_pub.cpp)
add_dependencies(image_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(image_pub ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(image_read src/image_read.cpp)
add_dependencies(image_read ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(image_read ${catkin_LIBRARIES} ${OpenCV_LIBS})
