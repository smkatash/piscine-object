#pragma once
#include <iostream>

enum State{
	SpeedingUp,
	Maintaining,
	Braking,
	Stopped,
};

class Speed {
    private:
        float   _speed;
        float   _speedLimit;
        float   _maxAccelerationForce;
        float   _maxBrakeForce;
        State   _state;
        float   calculateAcceleration(float time);
        float   calculateDeceleration(float time);
        float calculateDistanceDuringAcceleration(float initialSpeed, float acceleration, float time);
        float calculateDistanceDuringDeceleration(float initialSpeed, float deceleration, float time);
    public:
        Speed();
        ~Speed();
        void    setMaxAccelerationForce(float force);
        void    setSpeedLimit(float limit);
        void    setMaxBrakeForce(float force);
        float   accelerate(float time);
        float   decelerate(float time);
        float   getDecelerationPoint();
        State   getCurrentState();
        float   getSpeed();
        void    applyEmergencyBrakes();
};
