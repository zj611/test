#include "ros/ros.h"
#include <service_demo/greeting.h>

bool handle_function(service_demo::greeting::Request &req, service_demo::greeting::Response &res)
{
    res.sum=req.a+req.b;
    ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    //ROS_INFO("Request from %s with age %d",req.name.c_str(),req.age);//显示请求信息
    //处理请求，处理结果写入responce
    //res.feedback= "hi"+req.name +", I am server!";
    return true;

}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"server_point");
    ros::NodeHandle nh;
    ros::ServiceServer service=nh.advertiseService("greetings",handle_function);
    ROS_INFO("success to handle it!.");
    ros::spin();
    return 0;

}
