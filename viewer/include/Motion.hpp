#ifndef __VIEWER_MOTION_HPP__
#define __VIEWER_MOTION_HPP__
#include "Pose.hpp"
#include "Time.hpp"
namespace viewer{
    class Motion{
    public:
        Pose pose;
        Time time;

        Motion(const Pose& pose, const Time& time);
        Motion(Pose&& pose, Time&& time);
    };
}
#endif
