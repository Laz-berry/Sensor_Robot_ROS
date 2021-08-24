#include <pub_name.hpp>

namespace pub_name
{
    PubName::PubName()
    {
        pub_name_ = nh.advertise<pub_name::name_msg>("/my_name", 100);
    }
    PubName::~PubName()
    {

    }

    void PubName::run()
    {
        name_.string_data.data = makeString();

        pub_name_.publish(name_);
    }

    std::string PubName::makeString()
    {
        std::string ss;
        ss = "Park JunSeok / ";
        return ss;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_name");

    pub_name::PubName PN;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        PN.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}