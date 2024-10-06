#include "Scheduler.hpp"

Scheduler*  Scheduler::getInstance() {
    if (_instance == nullptr) {
		_instance = new Scheduler();
    }
	return _instance;
}

void    Scheduler::addTrain(Train* train) {
    if (find(this->_trains.begin(), this->_trains.end(), train) == this->_trains.end()) {
        this->_trains.push_back(train);
    }
}

void    Scheduler::addTrainComposition(TrainComposition* composition) {
    if (find(this->_trainCompositions.begin(), this->_trainCompositions.end(), composition) == this->_trainCompositions.end()) {
        this->_trainCompositions.push_back(composition);
    }
}

void    Scheduler::addRail(Rail* rail) {
    if (find(this->_network.begin(), this->_network.end(), rail) == this->_network.end()) {
        this->_network.push_back(rail);
    }
}
void    Scheduler::addNode(Node* node) {
    if (find(this->_nodes.begin(), this->_nodes.end(), node) == this->_nodes.end()) {
        this->_nodes.push_back(node);
    }
}
void    Scheduler::addEvent(Event *event) {
    if (find(this->_events.begin(), this->_events.end(), event) == this->_events.end()) {
        this->_events.push_back(event);
    }
}

Train*  Scheduler::getTrain(const std::string p_name) {
    std::vector<Train*>::iterator   it = this->_trains.begin();
    for (; it != this->_trains.end(); ++it) {
        if ((*it)->getName()->compare(p_name) == 0) {
            return *it;
        }
    }
    return nullptr;
}

Node*   Scheduler::getNode(const std::string p_name) {
    std::vector<Node*>::iterator   it = this->_nodes.begin();
    for (; it != this->_nodes.end(); ++it) {
        if ((*it)->getName()->compare(p_name) == 0) {
            return *it;
        }
    }
    return nullptr;
}
