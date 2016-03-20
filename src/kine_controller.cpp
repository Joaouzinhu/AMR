#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    double v=0.05, w=0, r= 0.1,b = 0.35;
    ros::init(argc,argv,"ros_Ctrl");
    ros::NodeHandle node;
    ros::Publisher pub1 = node.advertise<std_msgs::Float64>("vrep/vehicle/motorLeftSpeed",1);
    ros::Publisher pub2 = node.advertise<std_msgs::Float64>("vrep/vehicle/motorRightSpeed",1);
    ros::Rate loop_rate(60);
    
    std_msgs::Float64 w_right;
    std_msgs::Float64 w_left;
    
    while( ros::ok())
    {
        w_right.data = (v - ((b/2)*w))/r;
        w_left.data = (v - ((b/2)*w))/r;
        
        pub1.publish(w_left);
        pub2.publish(w_right);
        
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}