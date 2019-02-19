//
// Created by zj on 18-11-20.
//
#include "ros/ros.h"
#include <service_demo/greeting.h>
#include <iostream>

using namespace std;
int request_response(int x,int y)
{
	ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<service_demo::greeting>("greetings");//服务

    service_demo::greeting srv;
    srv.request.a=x;
    srv.request.b=y;

    if(client.call(srv))//关键语句
    {
       //ROS_INFO("Sum: %ld", (long int)srv.response.sum);
        return srv.response.sum;
    }
    else
    {
        ROS_ERROR("Failed to call service greeting.");
        return 1;
    }
}




int main(int argc,char** argv)
{
    ros::init(argc,argv,"request_point");
    //int i=100;
    int a=12,b=24,c,count=0;
  

   
   for(int i=50;i>0;i--)
    {
		if(i>25)
		{	
			c=request_response(a+i,b+i);
    		ROS_INFO("Sum: %d", c);
    		cout<<"sum: "<<c<<"        No: "<<++count<<endl;
    		
		}
		else
		{
			
			ROS_INFO("calcultion ends!");
			cout<<"calcultion ends!    No: "<<++count<<endl;
    	}
    	
    }
    
    return 0;
}



/*
//原始可用的程序
int main(int argc,char** argv)
{
    ros::init(argc,argv,"greetings_server");
    if (argc != 3)
    {
        ROS_INFO("usage: add_two_ints_client X Y");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<service_demo::greeting>("greetings");//服务

    service_demo::greeting srv;
    srv.request.a=atoll(argv[1]);
    srv.request.b=atoll(argv[2]);

    //srv.request.name="HAN";
    //srv.request.age="20";

    if(client.call(srv))//关键语句
    {
        ROS_INFO("Sum: %ld", (long int)srv.response.sum);
        //ROS_INFO("Feedback from server:%s.",srv.response.feedback);
    }
    else
    {
        ROS_ERROR("Failed to call service greeting.");
        return 1;
    }
    return 0;
}
*/
