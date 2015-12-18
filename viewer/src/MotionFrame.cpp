#include "MotionFrame.hpp"

namespace viewer{
    MotionFrame::MotionFrame(const Pose& pose, const Time& time)
        :pose(pose), time(time){
        
    }
    
    MotionFrame::MotionFrame(Pose&& pose, Time&& time)
        :pose(pose), time(time){
        
    }
}