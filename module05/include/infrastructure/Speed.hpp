#pragma once

class Speed {
    private:
        float   _speed;
        float   _maxAccelerationForce;
        float   _maxBrakeForce;
    public:
        Speed(): _speed(0), _maxAccelerationForce(0), _maxBrakeForce(0) {}
        ~Speed() {}

        void    setMaxAccelerationForce(float force) {
            this->_maxAccelerationForce = force;
        }

        void    setMaxBrakeForce(float force) {
            this->_maxBrakeForce = force;
        }

        void    accelerate(float speed) {
            this->_speed = speed;
        }

        void apply_force_on_brakes(float force) {
            float deceleration = force * this->_speed / 100;
            this->_speed -= deceleration;

            if (this->_speed < 0) {
                this->_speed = 0;
            }
        }

        void apply_emergency_brakes() {
            this->_speed = 0;
        }
};
