#include "TrcReader.hpp"
#include <string>
#include <boost/filesystem.hpp>
namespace viewer{
    TrcReader::TrcReader(){
        
    }
    
    TrcReader::TrcReader(const std::string& filepath){
        this->open(filepath);
    }
    
    int TrcReader::open(const std::string &filepath){
        boost::filesystem::path p(filepath);
        return 0;
    }
    
    void TrcReader::readNext(Pose& pose){
        
    }
    
    void TrcReader::close(){
        
    }
}