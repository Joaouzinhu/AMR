#include<ros/ros.h>
#include <std_msgs/Float32.h>

std_msgs::Float32 msg_sonar;
ros::Publisher pub_Sonar;

void callback(const std_msgs::FLoat32COnstPtr &msg_sonar)
{
    
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"LSon");
    
    ros::NoseHandle node;
    
    pub_Sonar = node.advertise<std_msgs::Float32>("ros_Sonar",1);
    
    ros::Subscreiber sub = node.subscribe("/vrep/vehicle/frontSonar")
}