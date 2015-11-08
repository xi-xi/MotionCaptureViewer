#ifndef __VIEWER_TRCREADER_HPP__
#define __VIEWER_TRCREADER_HPP__
#include "MotionReader.hpp"
#include <cstddef>
#include <fstream>
#include <list>
#include <string>
#include "Pose.hpp"
namespace viewer{
    class TrcReader : public MotionReader{
    public:
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
        enum TRC_JOINT_INDEX{
            TRC_JOINT_INDEX_FRAME,
            TRC_JOINT_INDEX_TIME,
            TRC_JOINT_INDEX_TOP_HEAD,
            TRC_JOINT_INDEX_BACK_HEAD,
            TRC_JOINT_INDEX_FRONT_HEAD,
            TRC_JOINT_INDEX_L_HEAD_OFFSET,
            TRC_JOINT_INDEX_R_SHOULDER,
            TRC_JOINT_INDEX_L_SHOULDER,
            TRC_JOINT_INDEX_NECK,
            TRC_JOINT_INDEX_L_BACKOFFSET,
            TRC_JOINT_INDEX_R_BICEP,
            TRC_JOINT_INDEX_R_ELBOW,
            TRC_JOINT_INDEX_R_FOREARM,
            TRC_JOINT_INDEX_R_RADIUS,
            TRC_JOINT_INDEX_R_ULNA,
            TRC_JOINT_INDEX_R_THUMB,
            TRC_JOINT_INDEX_R_PINKY,
            TRC_JOINT_INDEX_L_BICEP,
            TRC_JOINT_INDEX_L_ELBOW,
            TRC_JOINT_INDEX_L_FOREARM,
            TRC_JOINT_INDEX_L_RADIUS,
            TRC_JOINT_INDEX_L_ULNA,
            TRC_JOINT_INDEX_L_THUMB,
            TRC_JOINT_INDEX_L_PINKY,
            TRC_JOINT_INDEX_R_ASIS,
            TRC_JOINT_INDEX_L_ASIS,
            TRC_JOINT_INDEX_R_PSIS,
            TRC_JOINT_INDEX_L_PSIS,
            TRC_JOINT_INDEX_V_SACRAL,
            TRC_JOINT_INDEX_R_THIGH,
            TRC_JOINT_INDEX_R_KNEE,
            TRC_JOINT_INDEX_R_SHANK,
            TRC_JOINT_INDEX_R_ANKLE,
            TRC_JOINT_INDEX_R_HEEL,
            TRC_JOINT_INDEX_R_TOE,
            TRC_JOINT_INDEX_R_FOOT,
            TRC_JOINT_INDEX_L_THIGH,
            TRC_JOINT_INDEX_L_KNEE,
            TRC_JOINT_INDEX_L_SHANK,
            TRC_JOINT_INDEX_L_ANKLE,
            TRC_JOINT_INDEX_L_TOE,
            TRC_JOINT_INDEX_L_HEEL,
            TRC_JOINT_INDEX_L_FOOT
        };
        static const std::string DATACELL_DELIM;
        static Pose::JointName index2name(const TRC_JOINT_INDEX& index);
        std::ifstream input_stream_;
        void createPose(const std::list<std::string>& posedata, Motion& pose);
    };
}
#endif
