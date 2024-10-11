#include "Train.hpp"

Train::Train(std::string p_name, float p_maxAccelerationForce, float p_maxBrakeForce):
    _name(p_name) {
        this->_speed.setMaxAccelerationForce(p_maxAccelerationForce);
        this->_speed.setMaxBrakeForce(p_maxBrakeForce);
}

Train::~Train() {}

const std::string*   Train::getName() {
    return &this->_name;
}

void    Train::setScheduler(Scheduler* scheduler) {
    this->_scheduler = scheduler;
}

void    Train::estimateTime(std::pair<std::vector<Rail*>, float> route) {
    if (!this->_scheduler) {
        throw std::runtime_error("No Scheduler assigned for time estimation!");
    }
    float totalDistance = route.second;
    float railDistance;
    float hour = 0;
    float distance = 0;
    float timeInMinutes = 5.0f;
    float timeInHours = timeInMinutes / 60.0f;
    size_t nodes = route.first.size();
    size_t currentNode = 0;
    for (Rail* rail: route.first) {
        railDistance = rail->getLength();
        this->_speed.setSpeedLimit(rail->getMaxSpeedAllowed());
        while (railDistance > 0) {
            if (totalDistance <= this->_speed.getDecelerationPoint()) {
                distance = this->_speed.decelerate(timeInHours);
            } else {
                distance = this->_speed.accelerate(timeInHours);
                if (distance > railDistance) {
                    distance = railDistance;
                    timeInHours = distance / this->_speed.getSpeed();
                }
            }
            hour += timeInHours;
            railDistance = std::max(0.0f, railDistance - distance);
            totalDistance = std::max(0.0f, totalDistance - distance);
            if (totalDistance <= 0) {
                this->_scheduler->logEstimatedTravelTime(hour);
                return ;
            }
        }
    }
    this->_scheduler->logEstimatedTravelTime(hour);
}

void    Train::run(std::pair<std::vector<Rail*>, float> route, std::map<Rail*, float> events) {
    if (!this->_scheduler) {
        throw std::runtime_error("No Scheduler assigned to follow train movement!");
    }
    float totalDistance = route.second;
    float railDistance;
    float hour = 0;
    float distance = 0;
    float timeInMinutes = 5.0f;
    float timeInHours = timeInMinutes / 60.0f;
    size_t nodes = route.first.size();
    size_t currentNode = 0;
    for (Rail* rail: route.first) {
        railDistance = rail->getLength();
        this->_speed.setSpeedLimit(rail->getMaxSpeedAllowed());
        if (events.find(rail) != events.end()) {
            hour += events[rail];
            if (hour > 0) {
                this->_scheduler->logDelayEvent(events[rail]);
            }
        }
        while (railDistance > 0) {
            if (totalDistance <= this->_speed.getDecelerationPoint()) {
                distance = this->_speed.decelerate(timeInHours);
            } else {
                distance = this->_speed.accelerate(timeInHours);
                if (distance > railDistance) {
                    distance = railDistance;
                    timeInHours = distance / this->_speed.getSpeed();
                }
            }
            hour += timeInHours;
            railDistance = std::max(0.0f, railDistance - distance);
            totalDistance = std::max(0.0f, totalDistance - distance);
            if (totalDistance <= 0) {
                totalDistance = 0;
                this->_speed.applyEmergencyBrakes();
                this->_scheduler->logTrainStatus(hour, rail,totalDistance, this->_speed);
                this->_scheduler->logTrainNode(currentNode, nodes);
                return;
            }
            this->_scheduler->logTrainStatus(hour, rail, totalDistance, this->_speed);
            this->_scheduler->logTrainNode(currentNode, nodes);
        }
        currentNode++;
    }
}
