#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <pub_major/major_msg.h>

namespace pub_major
{
    class PubMajor
    {
        public:
            PubMajor();
            ~PubMajor();

            void run();
            std::string makeString();

        private:
            ros::NodeHandle nh;

            ros::Publisher pub_major_;

            pub_major::major_msg major_;
    };
}