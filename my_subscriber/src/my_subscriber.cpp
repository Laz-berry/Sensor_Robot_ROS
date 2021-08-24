#include "ros/ros.h"
#include "std_msgs/String.h"

void callbackMyNumber(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("my_department_num is [%s]", msg->data.c_str());
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "my_subscriber");

    ros::NodeHandle nh;

    ros::Subscriber sub_pub_num_ = nh.subscribe("/my_first_msg", 100, callbackMyNumber);

    ros::spin();
   
    return 0;
}