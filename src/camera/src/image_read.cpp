//
// Created by zj on 18-11-18.
//

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sstream>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace std;
using namespace cv;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{

    try
    {
        clock_t startTime=clock();
        //cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);

        Mat frame = cv_bridge::toCvCopy(msg, "bgr8")->image;
        ROS_INFO("image_msg size is:         %d x %d", msg->height,msg->width);
        ROS_INFO("subscribed image size is:  %d x %d", frame.rows,frame.cols);
        //用于将ROS图像消息转化为Opencv支持的图像格式（采用BGR8编码方式）
        //这部分代码的用法恰好与发布者节点中的作用相反
        //从opencv图像到ros的图像消息    sensor_msgs::ImagePtr msg1 = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();

        //sensor_msgs/Image.msg
        //std_msgs/Header header
        // uint32 height
        //uint32 width
        //string encoding
        //uint8 is_bigendian
        //uint32 step
        //uint8[] data
        clock_t endTime=clock();
        double dt=double(endTime-startTime)/CLOCKS_PER_SEC;
        ROS_INFO("single frame time is : %f s",dt);
        //cout<<"单帧计算时间:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;//不显示？？？
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_listener");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);
    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe("camera/image_raw", 1, imageCallback);
    ros::spin();

    loop_rate.sleep();//对订阅不起作用，只要话题有消息发布就订阅;对发布起作用，规定消息发布的频率
}
