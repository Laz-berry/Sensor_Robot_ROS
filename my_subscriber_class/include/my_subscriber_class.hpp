#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <pub_department_number.hpp>

namespace my_subscriber_class
{
    class MySubscriberClass
    {
        public:
            MySubscriberClass();
            ~MySubscriberClass();

            void callbackClassMsg(const pub_department_number::ConstPtr &msg);
            void run();
            
        private:
            ros::NodeHandle nh;

            ros::Subscriber sub_number_msg_;
            
            std::string str_;
    };
}