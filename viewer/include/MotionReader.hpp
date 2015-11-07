#ifndef __VIEWER_MOTIONREADER_HPP__
#define __VIEWER_MOTIONREADER_HPP__
#include <string>
namespace viewer{
    class Motion;
}
namespace viewer{
    class MotionReader{
    public:
        MotionReader();
        MotionReader(const std::string& filepath);
        virtual int open(const std::string& filepath) = 0;
        virtual bool isOpened()const = 0;
        virtual void readNext(Motion& motion) = 0;
        MotionReader& operator >> (Motion& motion){
            this->readNext(motion);
            return *this;
        }
        virtual void close() = 0;

    protected:

    private:
    };
}
#endif
