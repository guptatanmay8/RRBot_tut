#include<ros/ros.h>
#include<std_msgs/Float64.h>
#include<bits/stdc++.h>

int main(int argc, char** argv)
{
	ros::init(argc,argv,"publish_angles");
	ros::NodeHandle nh;
	ros::Publisher pub1= nh.advertise<std_msgs::Float64&>("/rrbot/joint1_position_controller/command",10);
	ros::Publisher pub2= nh.advertise<std_msgs::Float64&>("/rrbot/joint2_position_controller/command",10);
	ros::Rate loopRate(30);
	std_msgs::Float64 F1,F2;
	float f1,f2;
	std::cin>>f1>>f2;
	F1.data=f1; F2.data=f2;
	pub1.publish(F1);
	pub2.publish(F2);
	while(ros::ok())
	{
		loopRate.sleep();
	}
}
