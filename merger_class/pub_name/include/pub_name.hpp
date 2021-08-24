#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <pub_name/name_msg.h>

namespace pub_name
{
    class PubName
    {
        public:
            PubName();
            ~PubName();

            void run();
            std::string makeString();

        private:
            ros::NodeHandle nh;

            ros::Publisher pub_name_;

            pub_name::name_msg name_;
    };
}