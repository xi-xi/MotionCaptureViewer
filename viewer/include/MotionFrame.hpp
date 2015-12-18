#ifndef __VIEWER_MOTIONFRAME_HPP__
#define __VIEWER_MOTIONFRAME_HPP__
#include "Pose.hpp"
#include "Time.hpp"
namespace viewer{
    class MotionFrame{
    public:
        Pose pose;
        Time time;

        MotionFrame(const Pose& pose, const Time& time);
        MotionFrame(Pose&& pose, Time&& time);
    };
}
#endif
