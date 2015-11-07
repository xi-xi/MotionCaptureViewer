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
            case Back_Head:
                return Pose::JointName::BackHead;
            case Front_Head:
                return Pose::JointName::FrontHead;
            case L_Ankle:
                return Pose::JointName::LAnkle;
            case L_ASIS:
                return Pose::JointName::LASIS;
            case L_BackOffset:
                return Pose::JointName::LBackOffset;
            case L_Bicep:
                return Pose::JointName::LBicep;
            case L_Elbow:
                return Pose::JointName::LElbow;
            case L_Foot:
                return Pose::JointName::LFoot;
            case L_Forearm:
                return Pose::JointName::LForearm;
            case L_Head_Offset:
                return Pose::JointName::LHeadOffset;
            case L_Heel:
                return Pose::JointName::LHeel;
            case L_Knee:
                return Pose::JointName::LKnee;
            case L_Pinky:
                return Pose::JointName::LPinky;
            case L_PSIS:
                return Pose::JointName::LPSIS;
            case L_Radius:
                return Pose::JointName::LRadius;
            case L_Shank:
                return Pose::JointName::LShank;
            case L_Shoulder:
                return Pose::JointName::LShoulder;
            case L_Thigh:
                return Pose::JointName::LThigh;
            case L_Thumb:
                return Pose::JointName::LThumb;
            case L_Toe:
                return Pose::JointName::LToe;
            case L_Ulna:
                return Pose::JointName::LUlna;
            case Neck:
                return Pose::JointName::Neck;
            case R_Ankle:
                return Pose::JointName::RAnkle;
            case R_ASIS:
                return Pose::JointName::RASIS;
            case R_Bicep:
                return Pose::JointName::RBicep;
            case R_Elbow:
                return Pose::JointName::RElbow;
            case R_Foot:
                return Pose::JointName::RFoot;
            case R_ForeArm:
                return Pose::JointName::RForeArm;
            case R_Heel:
                return Pose::JointName::RHeel;
            case R_Knee:
                return Pose::JointName::RKnee;
            case R_Pinky:
                return Pose::JointName::RPinky;
            case R_PSIS:
                return Pose::JointName::RPSIS;
            case R_Radius:
                return Pose::JointName::RRadius;
            case R_Shank:
                return Pose::JointName::RShank;
            case R_Shoulder:
                return Pose::JointName::RShoulder;
            case R_Thigh:
                return Pose::JointName::RThigh;
            case R_Thumb:
                return Pose::JointName::RThumb;
            case R_Toe:
                return Pose::JointName::RToe;
            case R_Ulna:
                return Pose::JointName::RUlna;
            case Top_head:
                return Pose::JointName::TopHead;
            case V_Sacral:
                return Pose::JointName::VSacral;
            default:
                throw std::invalid_argument("JOINT_INDEX Time and Frame is not supported!!");
        }
    }
}