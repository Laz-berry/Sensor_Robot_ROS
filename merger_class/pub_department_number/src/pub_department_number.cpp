#include <pub_department_number.hpp>

namespace pub_department_number
{
    PubDepartmentNumber::PubDepartmentNumber()
    {
        pub_department_number_ = nh.advertise<pub_department_number::number_msg>("/my_department_number", 100);
    }
    PubDepartmentNumber::~PubDepartmentNumber()
    {

    }

    void PubDepartmentNumber::run()
    {
        department_number_.string_data.data = makeString();

        pub_department_number_.publish(department_number_);
    }

    std::string PubDepartmentNumber::makeString()
    {
        std::string ss;
        ss = "20170363 / ";
        return ss;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_department_number");

    pub_department_number::PubDepartmentNumber PDN;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        PDN.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}