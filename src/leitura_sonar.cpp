#include<ros/ros.h>
#include <std_msgs/Float32.h>

std_msgs::Float32 msg_sonar;
ros::Publisher pub_Sonar;

void callback(const std_msgs::Float32ConstPtr &msg)
{
    msg_sonar.data = msg->data;
    pub_Sonar.publish(msg_sonar);
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"LSon");
    
    ros::NodeHandle node;
    
    pub_Sonar = node.advertise<std_msgs::Float32>("ros_Sonar",1);
    
    ros::Subscriber sub = node.subscribe("/vrep/vehicle/frontSonar",1,callback);
    
    ros::spin();
    return 0;
}