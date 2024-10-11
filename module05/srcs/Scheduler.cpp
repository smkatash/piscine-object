#include "Scheduler.hpp"

Scheduler* Scheduler::_instance = nullptr;

Scheduler::~Scheduler() {
    std::vector<Rail*>::iterator nit = _network.begin();
    for (; nit != _network.end(); ++nit) {
        delete *nit;
    }
    std::vector<Node*>::iterator it = _nodes.begin();
    for (; it != _nodes.end(); ++it) {
        delete *it;
    }
    std::vector<Event*>::iterator ite = _events.begin();
    for (; ite != _events.end(); ++ite) {
        delete *ite;
    }
    std::vector<Train*>::iterator itt = _trains.begin();
    for (; itt != _trains.end(); ++itt) {
        delete *itt;
    }
    std::vector<TrainComposition*>::iterator cit = _trainCompositions.begin();
    for (; cit != _trainCompositions.end(); ++cit) {
        delete *cit;
    }
}

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

std::vector<Rail*>  Scheduler::getNetwork() { return this->_network ;}
std::vector<Node*>  Scheduler::getAllNodes() { return this->_nodes; }

void Scheduler::renderPath() {
    std::stringstream message;
    this->_pathFinder.setNetwork(getNetwork());
    this->_pathFinder.setNodes(getAllNodes());
    for (TrainComposition* compostion : this->_trainCompositions) {
        compostion->getTrain()->setScheduler(this->_instance);
        std::string logFile = *compostion->getTrain()->getName() + ".log";
        this->_logger.setLogFile(logFile);
        std::pair<std::vector<Rail*>, float> data = this->_pathFinder.findShortestPath(compostion);
        std::vector<Rail*> routes = data.first;
        std::map<Rail*, float> events = this->detectEventsOnRail(routes);
        float totalLength = data.second;
        message.clear();
        message.str("");
        message << "Train " << *compostion->getTrain()->getName() << std::endl;
        this->_logger.write(message.str());
        if (routes.size() > 0) {
            compostion->getTrain()->estimateTime(data);
            compostion->getTrain()->run(data, events);
        } else {
            message.clear();
            message << " No optimal route found.\n";
            this->_logger.write(message.str());
        }
    }
}

std::map<Rail*, float>  Scheduler::detectEventsOnRail(std::vector<Rail*> routes) {
    std::map<Rail*, float> eventsOnPath;
    float delay;
    for (Event* event: this->_events) {
        Node* node = event->getLocation();
        for (Rail* route: routes) {
            Node* departureNode = route->getDepartureNode() ;
            if  (departureNode->getName() == node->getName() &&
                this->isEventOccurred(event->getProbability())) {
                delay = event->getDuration();
                if (eventsOnPath.find(route) != eventsOnPath.end()) {
                    eventsOnPath[route] += delay;
                } else {
                    eventsOnPath.insert(std::make_pair(route, delay));
                }
            }
        }   
    }
    return eventsOnPath;
}

std::string Scheduler::stateToString(State state) {
    switch (state) {
        case SpeedingUp:
            return "Speed up";
        case Maintaining:
            return "Maintain";
        case Braking:
            return "Braking";
        case Stopped:
            return "Stopped";
        default:
            return "Unknown State";
    }
}

void Scheduler::logTrainStatus(float hour, Rail* rail, float totalDistance, Speed speed) {
    int hours = static_cast<int>(hour);
    int minutes = static_cast<int>((hour - hours) * 60);

    std::stringstream message;
    message << "[" << hours << "h" << std::setw(2) << std::setfill('0') << minutes << "m] - "
              << "[" << *rail->getDepartureNode()->getName() << "]"
              << " -> [" << *rail->getArrivalNode()->getName() << "] - "
              << "[" << std::fixed << std::setprecision(2) << std::setw(6) << totalDistance << " km] "
              << "[" << this->stateToString(speed.getCurrentState()) << "] - "
                << std::fixed << std::setprecision(2) << speed.getSpeed() << " km/h - ";
    this->_logger.write(message.str());
}

void Scheduler::logDelayEvent(float delay) {
    int hours = static_cast<int>(delay);
    int minutes = static_cast<int>((delay - hours) * 60);
    std::stringstream message;
    message << "Estimated delay time - " << hours << "h" << std::setw(2) << std::setfill('0') << minutes << "m. "
    << "Dear passangers, we are sorry for the delay due to the Event on the station.\n";
    this->_logger.write(message.str());
}


void Scheduler::logEstimatedTravelTime(float hour) {
    int hours = static_cast<int>(hour);
    int minutes = static_cast<int>((hour - hours) * 60);
    std::stringstream message;
    message << "Estimated optimal travel time : " << hours << "h" << std::setw(2) << std::setfill('0') << minutes << "m" << std::endl;
    this->_logger.write(message.str());
}

void Scheduler::logTrainNode(size_t currentNode, size_t totalNodeCount) {
    std::stringstream message;
    for (size_t i = 0; i < totalNodeCount; ++i) {
        if (currentNode == i) {
            message << "[x]";
        } else {
            message << "[ ]";
        }
    }
    message << std::endl;
    this->_logger.write(message.str());
}


bool Scheduler::isEventOccurred(float probability) {
    float randomValue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return randomValue <= probability;
}

void Scheduler::debug() {
    std::cout << "Listing all nodes\n";
    for (Node* node: _nodes) {
        std::cout << *node->getName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Listing all trains\n";
    for (Train* train: _trains) {
        std::cout << *train->getName() << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Listing all events\n";
    for (Event* event: _events) {
        std::cout << event->getEventName() << ", ";
    }
    std::cout << std::endl;
    

    std::cout << "Listing network\n";
    for (Rail* rail: _network) {
        std::cout << "Depart at " << *rail->getDepartureNode()->getName();
        std::cout << ", Arrive at " << *rail->getArrivalNode()->getName();
        std::cout << ", Length " << rail->getLength() << std::endl;
    }

    std::cout << "Listing all compositions\n";
    for (TrainComposition* train: _trainCompositions) {
        std::cout << *train->getTrain()->getName() << " ";
        std::cout << *train->getDepartureNode()->getName() << " ";
        std::cout << *train->getArrivalNode()->getName() << " ";
        std::cout << train->getDepartureTime() << std::endl;
    }
    std::cout << std::endl;
}
