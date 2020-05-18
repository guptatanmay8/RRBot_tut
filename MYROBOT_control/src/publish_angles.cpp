#include<ros/ros.h>
#include<std_msgs/Float32.h>

int main(int argc, char** argv)
{
	ros::init(argc,argv,"publish_angles");
	ros::NodeHandle nh;
	ros Publisher pub1= nh.advertise<std_msgs::Float32>("/rrbot/joint1_position_controller/command",10);
	ros Publisher pub2= nh.advertise<std_msgs::Float32>("/rrbot/joint2_position_controller/command",10);
	ros::Rate loopRate(30);
	float f1,f2;
	cin>>f1>>f2;
	pub1.publish(f1);
	pub2.publish(f2);
	while(ros::ok())
	{
		loopRate.sleep();
	}
}
