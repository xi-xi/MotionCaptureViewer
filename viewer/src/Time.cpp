#include "Time.hpp"

namespace viewer{
    Time::Time()
        :frame(0), millisecond(.0){
        
    }
    
    Time::Time(std::size_t frame, double millisecond)
        :frame(frame), millisecond(millisecond){
        ;
    }
}