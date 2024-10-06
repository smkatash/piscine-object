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