#pragma once

namespace MapReduce
{
class TaskTracker {
public:
    TaskTracker(std::shared_ptr<MapReduce::Config> config):
        _config(config)
    {}

    void run();
private:
    std::shared_ptr<MapReduce::Config> _config;};

    void _mapperFunction();
    void _reducerFuncion();
};
