#ifndef __VIEWER_TRCREADER_HPP__
#define __VIEWER_TRCREADER_HPP__
#include "MotionReader.hpp"
namespace viewer{
    class TrcReader : public MotionReader{
    public:
        TrcReader();
        TrcReader(const std::string& filepath);
        virtual int open(const std::string& filepath);
        virtual void readNext(Pose& pose);
        MotionReader& operator >> (Pose& pose){
            this->readNext(pose);
            return *this;
        }
        virtual void close();

    protected:
    
    private:
    };
}
#endif
