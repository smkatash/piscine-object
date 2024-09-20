#ifndef SPEED_HPP
#define SPEED_HPP
#include <iostream>

class Speed {
    private:
        int _speed;
    public:
        Speed(): _speed(0) {}
        ~Speed() {}
        void    accelerate(int speed) {
            this->_speed = speed;
            std::cout << "Speed at: " << this->_speed << std::endl;
        }

        void apply_force_on_brakes(int force) {
            int deceleration = force * this->_speed / 100;
            this->_speed -= deceleration;

            if (this->_speed < 0) {
                this->_speed = 0;
            }

            std::cout << "Braking applied with force: " << force << ". Speed reduced to: " << this->_speed << std::endl;
        }

        void apply_emergency_brakes() {
            this->_speed = 0;
            std::cout << "Emergency brakes applied. Speed reduced to 0\n";
        }
};

#endif
