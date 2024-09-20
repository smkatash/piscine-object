#ifndef SHOVEL_HPP
#define SHOVEL_HPP
#include "ATool.hpp"

class Shovel: public ATool {
    private:
        void use();
    public:
        Shovel();
		~Shovel();
        int get_number_of_uses();
};

#endif
