#ifndef __VIEWER_MOTIONREADER_HPP__
#define __VIEWER_MOTIONREADER_HPP__
namespace std{
    class string;
}
namespace viewer{
    class Pose;
}
namespace viewer{
    class MotionReader{
    public:
        MotionReader();
        MotionReader(const std::string& filepath);
        virtual int open(const std::string& filepath) = 0;
        virtual void readNext(Pose& pose) = 0;
        MotionReader& operator >> (Pose& pose){
            this->readNext(pose);
            return *this;
        }
        virtual void close() = 0;

    protected:
    
    private:
    };
}
#endif
