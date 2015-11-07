#include "TrcReader.hpp"
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string.hpp>
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
    
    void TrcReader::readNext(Pose& pose){
        if(!this->isOpened()){
            return;
        }
        std::string line;
        if(!std::getline(this->input_stream_, line)){
            return;
        }
        std::list<std::string> tokens;
        boost::split(tokens,line, boost::is_any_of(TrcReader::DATACELL_DELIM));
        this->createPose(tokens, pose);
    }
    
    void TrcReader::close(){
        if(this->isOpened()){
            this->input_stream_.close();
        }
    }
    
    void TrcReader::createPose(const std::list<std::string> &posedata, Pose& pose){
    }
}