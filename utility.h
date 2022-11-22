#pragma once

#include <string>
#include <exception>
#include <iostream>

namespace MapReduce
{

struct Config {
    Config(char **argv) {
        this->jobName = std::string(argv[1]);
        this->numReducer = std::stoi(argv[2]);
        this->delay = std::stoi(argv[3]);
        this->inputFileName = std::string(argv[4]);
        this->chunkSize = std::stoi(argv[5]);
        this->localityConfigFileName = std::string(argv[6]);
        this->outputDir = std::string(argv[7]);
    }

    std::string jobName;
    std::string inputFileName;
    std::string localityConfigFileName;
    std::string outputDir;
    int numReducer;
    int delay;
    int chunkSize;
};

void deleteFile(const std::string &filePath) {
    int result;
    
    result = std::remove(filePath.c_str());
    if (result == -1) {
        std::string a =  "[Error]: can not remove file: " + filePath ;
        throw a;
    }
}

};
