#include"ros/ros.h"
#include"can/control.h"
#include<iostream>
using namespace std;

void msgCallback(const can::control::ConstPtr &msg2)
{
	cout<<"解析車速: "<<msg2->speed<<endl;
	cout<<"解析轉角: "<<msg2->angle<<endl;
	cout<<"----------------------"<<endl;
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"can_topic_test");
	ros::NodeHandle nh;
	ros::Subscriber can_sub=nh.subscribe("control_msg",100,msgCallback);
	ros::spin();
	return 0;
}
