#include <string_merger.hpp>

namespace string_merger
{
    StringMerger::StringMerger()
    {
        //todo
        major_ok_ = false;
        subject_ok_ = false;
        department_number_ok_ = false;
        name_ok_ = false;

        pub_merger_ = nh.advertise<std_msgs::String>("/my_infomation", 100);

        sub_department_number_ = nh.subscribe("/my_department_number", 100, &StringMerger::callbackDepartmentNumber, this);
        sub_major_ = nh.subscribe("/my_major", 100, &StringMerger::callbackMajor, this);
        sub_name_ = nh.subscribe("/my_name", 100, &StringMerger::callbackName, this);
        sub_subject_ = nh.subscribe("/my_subject", 100, &StringMerger::callbackSubject, this);
        str_1 = "";
        str_2 = "";
        str_3 = "";
        str_4 = "";
    }

    StringMerger::~StringMerger()
    {   

    }

    void StringMerger::callbackDepartmentNumber(const pub_department_number::number_msg::ConstPtr &ptr)
    {
        //todo
        department_number_ok_ = true;

        str_1 = ptr->string_data.data;
    }

    void StringMerger::callbackMajor(const pub_major::major_msg::ConstPtr &ptr)
    {
        //todo
        major_ok_ = true;

        str_2 = ptr->string_data.data;
    }

    void StringMerger::callbackName(const pub_name::name_msg::ConstPtr &ptr)
    {
        //todo
        name_ok_ = true;

        str_3 = ptr->string_data.data;
    }

    void StringMerger::callbackSubject(const pub_subject::subject_msg::ConstPtr &ptr)
    {
        //todo
        subject_ok_ = true;

        str_4 = ptr->string_data.data;
    }

    void StringMerger::run()
    {
        if( !(department_number_ok_ && major_ok_ && name_ok_ && subject_ok_) ) return;

        //todo
        str_10 = str_1 + str_2 + str_3 + str_4;
        std::cout << str_10 << std::endl;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "string_merger");

    string_merger::StringMerger SM;

    ros::Rate loop_rate(10);

    //todo
    while(ros::ok())
    {
        SM.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}