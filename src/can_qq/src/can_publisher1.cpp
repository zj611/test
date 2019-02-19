#include"ros/ros.h"
#include"can/frame.h"
#include<iostream>
#include<string>
using namespace std;
int main(int argc,char**argv)
{
	ros::init(argc,argv,"can_publisher_point");
	ros::NodeHandle nh;
	ros::Publisher can_hub=nh.advertise<can::frame>("can_topic_msg",100);
	ros::Rate loop_rate(10);//設定循環周期爲1hz/10hz
	can::frame msg1;
	while(ros::ok())
		{
			msg1.id=0x18FFEFFD;//車輛控制指令id
			msg1.data[0]=0x01;//0x01-啓動;0x00-熄火;0x11-已啓動
			msg1.data[1]=0xF1;//0xF1-前進;0XB1-後退
			msg1.data[2]=0x30;//0x30-前進速度30
			msg1.data[3]=0x00;//0x00-無制動;0x01-制動
			msg1.data[4]=0x01;//0x00-直線行駛;0x01-轉彎
			msg1.data[5]=0x30;//0x30方向盤轉角
			msg1.data[6]=0x00;//待定
			msg1.data[7]=0x00;//待定
			cout<<"can報文格式: "<<endl;
			ROS_INFO("%x",msg1.id);
			can_hub.publish(msg1);
			loop_rate.sleep();
		}
	return 0;
}


