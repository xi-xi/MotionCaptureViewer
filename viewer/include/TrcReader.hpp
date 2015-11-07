#ifndef __VIEWER_TRCREADER_HPP__
#define __VIEWER_TRCREADER_HPP__
#include "MotionReader.hpp"
#include <fstream>
#include <list>
#include <string>
namespace viewer{
    class TrcReader : public MotionReader{
    public:
        enum TRC_JOINT_INDEX{
            Frame,
            Time,
            Top_head,
            Back_Head,
            Front_Head,
            L_Head_Offset,
            R_Shoulder,
            L_Shoulder,
            Neck,
            L_BackOffset,
            R_Bicep,
            R_Elbow,
            R_ForeArm,
            R_Radius,
            R_Ulna,
            R_Thumb,
            R_Pinky,
            L_Bicep,
            L_Elbow,
            L_Forearm,
            L_Radius,
            L_Ulna,
            L_Thumb,
            L_Pinky,
            R_ASIS,
            L_ASIS,
            R_PSIS,
            L_PSIS,
            V_Sacral,
            R_Thigh,
            R_Knee,
            R_Shank,
            R_Ankle,
            R_Heel,
            R_Toe,
            R_Foot,
            L_Thigh,
            L_Knee,
            L_Shank,
            L_Ankle,
            L_Toe,
            L_Heel,
            L_Foot
        };

        TrcReader();
        TrcReader(const std::string& filepath);
        ~TrcReader();
        virtual int open(const std::string& filepath);
        virtual void readNext(Motion& motion);
        virtual bool isOpened()const;
        MotionReader& operator >> (Motion& motion){
            this->readNext(motion);
            return *this;
        }
        virtual void close();

    protected:

    private:
        static const std::string DATACELL_DELIM;
        std::ifstream input_stream_;
        void createPose(const std::list<std::string>& posedata, Motion& pose);
    };
}
#endif
