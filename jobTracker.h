#pragma once

#include "utility.h"

#include <memory>
#include <iostream>
#include <exception>

namespace MapReduce
{
class JobTracker {
public:
    JobTracker(std::shared_ptr<MapReduce::Config> config):
        _config(config)
    {}

    void run() {
        try {
            
        } catch (const std::string &error) {
            std::cout << error << std::endl;
        }
    }

private:
    std::shared_ptr<MapReduce::Config> _config;

    void _shuffle();
    void _scheduler();
};

};

