#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sstream>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace std;
using namespace cv;



int main(int argc, char **argv)
{
    ros::init(argc,argv,"video_publisher");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);//发布图片需要用到image_transport
    image_transport::Publisher pub = it.advertise("camera/image_raw", 1);

    //if(argc)
    //    cout<<argv[1]<<endl;

    ros::Rate loop_rate(10);
    //string path = "/media/zj/文档/dataset/01test/line1.mp4";
    //path = path + argv[1];//用户自己添加视频文件名字
    //VideoCapture cap("/media/zj/文档/dataset/line1.mp4");
    VideoCapture cap("/media/zj/文档/dataset/01test/video_left.avi");//open video from the path
    if(!cap.isOpened())
    {
        std::cout<<"open video failed!"<<std::endl;
        return -1;
    }
    else
        std::cout<<"open video success!"<<std::endl;
    Mat frame;//this is an image
    bool isSuccess = true;

    while(nh.ok())
    {
        isSuccess = cap.read(frame);
        //cap>>frame;
        cout << "----------successful-------------------" << endl;

        if(!isSuccess)//if the video ends, then break
        {
            std::cout<<"video ends"<<std::endl;
             break;
        }
        //将opencv的图片转换成ros的sensor_msgs，然后才能发布。
        sensor_msgs::ImagePtr msg1 = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();

        pub.publish(msg1);

        //cout<<"----------sl-------------------"<<endl;
        ROS_INFO("ROS msg is publishing...");
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
/*

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_publisher");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("camera/image", 1);
    //第一个参数是话题的名称，第二个是缓冲区的大小（即消息队列的长度，在发布图像消息时消息队列的长度只能是1
    cv::Mat image = imread("/home/zj/a/computer_vision/aa.jpg");
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
    ros::Rate loop_rate(5);//设置主题的发布频率为5Hz
    while (nh.ok())
    {
        cout<<"----"<<endl;
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
*/