#include "TrcReader.hpp"
#include <string>
#include <fstream>
#include <stdexcept>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string.hpp>
#include "Motion.hpp"
#include "Pose.hpp"
#include "Time.hpp"
namespace viewer{
    const std::string TrcReader::DATACELL_DELIM = "\t";
    TrcReader::TrcReader(){
        
    }
    
    TrcReader::TrcReader(const std::string& filepath){
        this->open(filepath);
    }
    
    TrcReader::~TrcReader(){
        this->close();
    }
    
    int TrcReader::open(const std::string &filepath){
        namespace bf = boost::filesystem;
        bf::path input_path(filepath);
        if(!bf::exists(input_path)){
            return -1;
        }
        this->input_stream_.open(input_path.string());
        if(!this->input_stream_.is_open()){
            return -1;
        }
        return 0;
    }
    
    bool TrcReader::isOpened()const{
        return this->input_stream_.is_open();
    }
    
    void TrcReader::readNext(Motion& motion){
        if(!this->isOpened()){
            return;
        }
        std::string line;
        if(!std::getline(this->input_stream_, line)){
            return;
        }
        std::list<std::string> tokens;
        boost::split(tokens,line, boost::is_any_of(TrcReader::DATACELL_DELIM), boost::token_compress_off);
        this->createPose(tokens, motion);
    }
    
    void TrcReader::close(){
        if(this->isOpened()){
            this->input_stream_.close();
        }
    }
    
    void TrcReader::createPose(const std::list<std::string> &posedata, Motion& motion){
        auto it = posedata.begin();
        Pose pose;
        Time time;
        time.frame = static_cast<decltype(time.frame)>(std::stoul(*it));
        ++it;
        time.second = std::stod(*it);
    }
    
    Pose::JointName TrcReader::index2name(const TRC_JOINT_INDEX& index){
        switch(index){
            case TRC_JOINT_INDEX_BACK_HEAD:
                return Pose::JointName::BackHead;
            case TRC_JOINT_INDEX_FRONT_HEAD:
                return Pose::JointName::FrontHead;
            case TRC_JOINT_INDEX_L_ANKLE:
                return Pose::JointName::LAnkle;
            case TRC_JOINT_INDEX_L_ASIS:
                return Pose::JointName::LASIS;
            case TRC_JOINT_INDEX_L_BACKOFFSET:
                return Pose::JointName::LBackOffset;
            case TRC_JOINT_INDEX_L_BICEP:
                return Pose::JointName::LBicep;
            case TRC_JOINT_INDEX_L_ELBOW:
                return Pose::JointName::LElbow;
            case TRC_JOINT_INDEX_L_FOOT:
                return Pose::JointName::LFoot;
            case TRC_JOINT_INDEX_L_FOREARM:
                return Pose::JointName::LForearm;
            case TRC_JOINT_INDEX_L_HEAD_OFFSET:
                return Pose::JointName::LHeadOffset;
            case TRC_JOINT_INDEX_L_HEEL:
                return Pose::JointName::LHeel;
            case TRC_JOINT_INDEX_L_KNEE:
                return Pose::JointName::LKnee;
            case TRC_JOINT_INDEX_L_PINKY:
                return Pose::JointName::LPinky;
            case TRC_JOINT_INDEX_L_PSIS:
                return Pose::JointName::LPSIS;
            case TRC_JOINT_INDEX_L_RADIUS:
                return Pose::JointName::LRadius;
            case TRC_JOINT_INDEX_L_SHANK:
                return Pose::JointName::LShank;
            case TRC_JOINT_INDEX_L_SHOULDER:
                return Pose::JointName::LShoulder;
            case TRC_JOINT_INDEX_L_THIGH:
                return Pose::JointName::LThigh;
            case TRC_JOINT_INDEX_L_THUMB:
                return Pose::JointName::LThumb;
            case TRC_JOINT_INDEX_L_TOE:
                return Pose::JointName::LToe;
            case TRC_JOINT_INDEX_L_ULNA:
                return Pose::JointName::LUlna;
            case TRC_JOINT_INDEX_NECK:
                return Pose::JointName::Neck;
            case TRC_JOINT_INDEX_R_ANKLE:
                return Pose::JointName::RAnkle;
            case TRC_JOINT_INDEX_R_ASIS:
                return Pose::JointName::RASIS;
            case TRC_JOINT_INDEX_R_BICEP:
                return Pose::JointName::RBicep;
            case TRC_JOINT_INDEX_R_ELBOW:
                return Pose::JointName::RElbow;
            case TRC_JOINT_INDEX_R_FOOT:
                return Pose::JointName::RFoot;
            case TRC_JOINT_INDEX_R_FOREARM:
                return Pose::JointName::RForeArm;
            case TRC_JOINT_INDEX_R_HEEL:
                return Pose::JointName::RHeel;
            case TRC_JOINT_INDEX_R_KNEE:
                return Pose::JointName::RKnee;
            case TRC_JOINT_INDEX_R_PINKY:
                return Pose::JointName::RPinky;
            case TRC_JOINT_INDEX_R_PSIS:
                return Pose::JointName::RPSIS;
            case TRC_JOINT_INDEX_R_RADIUS:
                return Pose::JointName::RRadius;
            case TRC_JOINT_INDEX_R_SHANK:
                return Pose::JointName::RShank;
            case TRC_JOINT_INDEX_R_SHOULDER:
                return Pose::JointName::RShoulder;
            case TRC_JOINT_INDEX_R_THIGH:
                return Pose::JointName::RThigh;
            case TRC_JOINT_INDEX_R_THUMB:
                return Pose::JointName::RThumb;
            case TRC_JOINT_INDEX_R_TOE:
                return Pose::JointName::RToe;
            case TRC_JOINT_INDEX_R_ULNA:
                return Pose::JointName::RUlna;
            case TRC_JOINT_INDEX_TOP_HEAD:
                return Pose::JointName::TopHead;
            case TRC_JOINT_INDEX_V_SACRAL:
                return Pose::JointName::VSacral;
            default:
                throw std::invalid_argument("JOINT_INDEX Time and Frame is not supported!!");
        }
    }
}