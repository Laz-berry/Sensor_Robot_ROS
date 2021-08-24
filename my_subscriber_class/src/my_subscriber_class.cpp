#include <my_subscriber_class.hpp>

namespace my_subscriber_class
{
    MySubscriberClass::MySubscriberClass()
    {
        sub_number_msg_ = nh.subscribe("/my_department_number", 100, &MySubscriberClass::callbackClassMsg, this);
    
        str_ = "";
    }

    MySubscriberClass::~MySubscriberClass()
    {

    }

    void MySubscriberClass::callbackClassMsg(const pub_department_number::number_msg::ConstPtr &msg)
    {
        //std::cout << "my_subscriber node subscribes [ " <<msg->float_data.data << " , " << msg->string_data.data << " ]" << std::endl;
        str_ = msg->string_data.data;
    }

    void MySubscriberClass::run()
    {
        std::cout << "string data : " << str_ << std::endl;
    }
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "/my_department_number");

    my_subscriber_class::MySubscriberClass MSC;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        MSC.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}