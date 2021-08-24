#include <pub_major.hpp>

namespace pub_major
{
    PubMajor::PubMajor()
    {
        pub_major_ = nh.advertise<pub_major::major_msg>("/my_major", 100);
    }
    PubMajor::~PubMajor()
    {

    }

    void PubMajor::run()
    {
        major_.string_data.data = makeString();

        pub_major_.publish(major_);
    }

    std::string PubMajor::makeString()
    {
        std::string ss;
        ss = "Faculty of AI Convergence / ";
        return ss;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_major");

    pub_major::PubMajor PM;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        PM.run();

        loop_rate.sleep();
    }
}