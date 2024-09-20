#ifndef HAMMER_HPP
#define HAMMER_HPP
#include "ATool.hpp"

class Hammer: public ATool {
    private:
        void use();
    public:
        Hammer();
		~Hammer();
        int get_number_of_uses();
};

#endif
