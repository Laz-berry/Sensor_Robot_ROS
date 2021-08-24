#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <pub_department_number/number_msg.h>

namespace pub_department_number
{
    class PubDepartmentNumber
    {
        public:
            PubDepartmentNumber();
            ~PubDepartmentNumber();

            void run();
            std::string makeString();

        private:
            ros::NodeHandle nh;

            ros::Publisher pub_department_number_;

            pub_department_number::number_msg department_number_;
    };
}