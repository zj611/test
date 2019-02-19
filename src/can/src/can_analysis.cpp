#include"ros/ros.h"
#include<can/frame.h>
#include"can/control.h"
#include<iostream>
using namespace std;

ros::Publisher control_pub;
can::control msg2;

void msgCallback(const can::frame::ConstPtr &msg1)
{
	cout<<"---------------------------------"<<endl;
	cout<<"---------------------------------"<<endl;
	switch(msg1->id)  
	{
		case 0x18FFEFAD:
			cout<<"驾驶状态是否正常?"<<endl;
		if(msg1->data[7]==0x01)
		{
			cout<<"回复:驾驶状态正常!"<<endl;
		}
		else
		{
			cout<<"警告!驾驶状态异常!"<<endl;
		}	
		case 0x18FFEFFD:
			cout<<"CAN报文信息如下:"<<endl;
		    switch(msg1->data[0])
		    {
				case 0x01:
					cout<<"车辆启动"<<endl;
					break;
				case 0x00:
					cout<<"车辆熄火"<<endl;
					break;
				case 0x11:
					cout<<"车辆已启动"<<endl;
					break;
			}
		    switch(msg1->data[1])
		    {
				case 0xF1:
					cout<<"车辆前进"<<endl;
					break;
				case 0xB0:
					cout<<"车辆后退"<<endl;
					break;
			}
		    switch(msg1->data[2])
		    {
				case 0x30:
					cout<<"时速0km/h"<<endl;
					msg2.speed=30;
					break;
				case 0x40:
					cout<<"时速40km/h"<<endl;
					msg2.speed=40;
					break;
			}
		    switch(msg1->data[3])
		    {
				case 0x00:
					cout<<"无制动"<<endl;
					break;
				case 0x01:
					cout<<"制动状态"<<endl;
					break;
			}
		    switch(msg1->data[4])
		    {
				case 0x00:
					cout<<"直线行驶"<<endl;
					break;
				case 0x01:
					cout<<"弯道行驶"<<endl;
					break;
			}
		    switch(msg1->data[5])
		    {
				case 0x30:
					cout<<"以30度转角转弯"<<endl;
					msg2.angle=30;
					break;
				case 0x40:
					cout<<"以40度转角转弯"<<endl;
					msg2.angle=40;
					break;
			}
			break;
	}
	control_pub.publish(msg2);
	cout<<"××××××××××××××××××××××××××××××××××××××××××"<<endl;
}


int main(int argc,char** argv)
{
	ros::init(argc,argv,"can_topic_publisher");
	ros::NodeHandle nh;
	ros::Subscriber can_sub=nh.subscribe("can_topic_msg",100,msgCallback);
	control_pub=nh.advertise<can::control>("control_msg",100);
	//ros::Rate loop_rate(10);//設定循環周期爲1hz/10hz	
	ros::spin();//有訂閱的節點,必須增加這一句,否則回調函數不會被調用
	return 0;
}



