#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP
#include <iostream>

#define MAX_GEAR 6

class Transmission {
    private:
        int _gear;

    public:
        Transmission(): _gear(0) {}
        ~Transmission() {}
        void    shift_gears_up() {
            if (this->_gear + 1 <= MAX_GEAR) {
                this->_gear++;
            }
            std::cout << "Gear is on level: " << this->_gear << std::endl;
        }
        void    shift_gears_down() {
            if (this->_gear - 1 >= 0) {
                this->_gear--;
            } 
            std::cout << "Gear is on level: " << this->_gear << std::endl;
        }
        void    reverse() {
            this->_gear = -1;
            std::cout << "Gear is on level: " << this->_gear << std::endl;
        }
};

#endif
