#pragma once
#include "Parser.hpp"

class TrainDispatcher {
    private:
        NetworkParser _networkParser;
        TrainCompositionParser _trainParser;
        Scheduler* _scheduler;
    public: 
        TrainDispatcher();
        ~TrainDispatcher();
        void    loadNetworkData(std::string filePath);
        void    loadTrainData(std::string filePath);
        void    output();
};


