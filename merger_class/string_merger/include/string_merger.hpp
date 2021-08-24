#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>
#include <pub_department_number/number_msg.h>
#include <pub_major/major_msg.h>
#include <pub_name/name_msg.h>
#include <pub_subject/subject_msg.h>

namespace string_merger
{
    class StringMerger
    {
        public:
            StringMerger();
            ~StringMerger();

            void callbackMajor(const pub_major::major_msg::ConstPtr &ptr);
            void callbackSubject(const pub_subject::subject_msg::ConstPtr &ptr);
            void callbackDepartmentNumber(const pub_department_number::number_msg::ConstPtr &ptr);
            void callbackName(const pub_name::name_msg::ConstPtr &ptr);
            
            void run();

        private:

            //todo
            ros::Publisher pub_merger_;
            ros::NodeHandle nh;
            ros::Subscriber sub_department_number_;
            ros::Subscriber sub_major_;
            ros::Subscriber sub_subject_;
            ros::Subscriber sub_name_;

            bool major_ok_;
            bool subject_ok_;
            bool department_number_ok_;
            bool name_ok_;

            std::string str_1;
            std::string str_2;
            std::string str_3;
            std::string str_4;

            std::string str_10;
    };
}