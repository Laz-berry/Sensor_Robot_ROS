#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <pub_subject/subject_msg.h>

namespace pub_subject
{
    class PubSubject
    {
        public:
            PubSubject();
            ~PubSubject();

            void run();
            std::string makeString();

        private:
            ros::NodeHandle nh;

            ros::Publisher pub_subject_;

            pub_subject::subject_msg subject_;
    };
}