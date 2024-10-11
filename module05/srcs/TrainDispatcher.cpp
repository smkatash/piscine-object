#include "TrainDispatcher.hpp"

TrainDispatcher::TrainDispatcher() {
    this->_scheduler = Scheduler::getInstance();
}

TrainDispatcher::~TrainDispatcher() {
    delete this->_scheduler;
}

void    TrainDispatcher::loadNetworkData(std::string filePath) {
    this->_networkParser.parseData(filePath);
}
void    TrainDispatcher::loadTrainData(std::string filePath) {
    this->_trainParser.parseData(filePath);
}

void    TrainDispatcher::output() {
    this->_scheduler->renderPath();
}