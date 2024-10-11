#include "Speed.hpp"

Speed::Speed(): _speed(0), _speedLimit(0), _maxAccelerationForce(0), _maxBrakeForce(0), _state(Stopped) {}
Speed::~Speed() {}

void    Speed::setMaxAccelerationForce(float force) {
    this->_maxAccelerationForce = force;
}

void Speed::setSpeedLimit(float limit) {
    this->_speedLimit = limit;
}   

void Speed::setMaxBrakeForce(float force) {
    this->_maxBrakeForce = force;
}

State    Speed::getCurrentState() {
    return this->_state;
}

float Speed::calculateDistanceDuringAcceleration(float initialSpeed, float acceleration, float time) {
    float distance = (initialSpeed * time) + (0.5 * acceleration * time * time);
    return distance;
}

float Speed::calculateDistanceDuringDeceleration(float initialSpeed, float deceleration, float time) {
    float distance = (initialSpeed * time) - (0.5 * deceleration * time * time);
    return distance;
}


float    Speed::accelerate(float time) {
    float initialSpeed = this->_speed;
    float newSpeed = this->calculateAcceleration(time);
    float acceleration = (newSpeed - initialSpeed) / time;
    if (newSpeed == this->_speedLimit) {
        this->_speed = this->_speedLimit;
        this->_state = Maintaining;
    } else {
        this->_speed = newSpeed;
        this->_state = SpeedingUp;
    }
    return calculateDistanceDuringAcceleration(initialSpeed, acceleration, time);
}

float Speed::decelerate(float time) {
    float initialSpeed = this->_speed;
    float newSpeed = this->calculateDeceleration(time);
    float deceleration = (initialSpeed - newSpeed) / time;
    this->_speed = newSpeed;
    this->_state = Braking;

    if (this->_speed <= 0) {
        this->_state = Stopped;
        return (0);
    }
    return calculateDistanceDuringDeceleration(initialSpeed, deceleration, time); 
}

float   Speed::calculateAcceleration(float time) {
    float accelSpeed = this->_speed + (this->_maxAccelerationForce * time);
    if (this->_speedLimit != 0 && accelSpeed > this->_speedLimit) {
        return this->_speedLimit;
    }
    return accelSpeed;
}

float   Speed::calculateDeceleration(float time) {
    float newSpeed =  this->_speed - (this->_maxBrakeForce * time);
    if (newSpeed < 0) { return 0; }
    return newSpeed;
}

float Speed::getDecelerationPoint() {
    float speed = this->_speed;
    float deceleration = this->_maxBrakeForce;
    if (deceleration == 0) {
        return 0;
    }
    return (speed * speed) / (2 * deceleration);
}

float   Speed::getSpeed() { return this->_speed; }

void Speed::applyEmergencyBrakes() {
    this->_speed = 0;
    this->_state = Stopped;
}
