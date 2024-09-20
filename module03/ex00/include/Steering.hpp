#ifndef STEERING_HPP
#define STEERING_HPP

#include <iostream>
#define STEERING_RATION 16.0

class Steering {
    private:
        double  _wheel_angle;
        double _steering_ratio;
    public:
        Steering(): _wheel_angle(0), _steering_ratio(STEERING_RATION) {}
        ~Steering() {}
        void    turn_wheel(double angle) {
            this->_wheel_angle = angle / this->_steering_ratio;
            std::cout << "Steering Wheel Angle: " << this->_wheel_angle << "°\n";
        }
        void    straighten_wheels() {
            this->_wheel_angle = 0;
            std::cout << "Steering Wheel Angle: " << this->_wheel_angle << "° (straightened)\n";
        }
};

#endif
