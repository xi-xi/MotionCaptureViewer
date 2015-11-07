#ifndef __VIEWER_TRCREADER_HPP__
#define __VIEWER_TRCREADER_HPP__
#include "MotionReader.hpp"
#include <fstream>
#include <list>
#include <string>
namespace viewer{
    class TrcReader : public MotionReader{
    public:
        TrcReader();
        TrcReader(const std::string& filepath);
        ~TrcReader();
        virtual int open(const std::string& filepath);
        virtual void readNext(Pose& pose);
        virtual bool isOpened()const;
        MotionReader& operator >> (Pose& pose){
            this->readNext(pose);
            return *this;
        }
        virtual void close();

    protected:

    private:
        static const std::string DATACELL_DELIM;
        std::ifstream input_stream_;
        void createPose(const std::list<std::string>& posedata, Pose& pose);
    };
}
#endif
