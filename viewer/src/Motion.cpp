#include "Motion.hpp"

namespace viewer{
    Motion::Motion(const Pose& pose, const Time& time)
        :pose(pose), time(time){
        
    }
    
    Motion::Motion(Pose&& pose, Time&& time)
        :pose(pose), time(time){
        
    }
}