#ifndef __VIEWER_TIME_HPP__
#define __VIEWER_TIME_HPP__
#include <cstddef>
namespace viewer{
    class Time{
    public:
        Time();
        Time(std::size_t frame, double millisecond);
        std::size_t frame;
        double second;
    };
}
#endif