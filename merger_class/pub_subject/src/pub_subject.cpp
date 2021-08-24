#include <pub_subject.hpp>

namespace pub_subject
{
    PubSubject::PubSubject()
    {
        pub_subject_ = nh.advertise<pub_subject::subject_msg>("/my_subject", 100);
    }
    PubSubject::~PubSubject()
    {

    }

    void PubSubject::run()
    {
        subject_.string_data.data = makeString();

        pub_subject_.publish(subject_);
    }

    std::string PubSubject::makeString()
    {
        std::string ss;
        ss = "Sensor Motion Robot Engineer Lab / ";
        return ss;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_subject");

    pub_subject::PubSubject PS;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        PS.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}