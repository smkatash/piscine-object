#ifndef CAR_HPP
#define CAR_HPP
#include "Engine.hpp"
#include "Transmission.hpp"
#include "Speed.hpp"
#include "Steering.hpp"

class Car {
    public:
        Engine          engine;
        Transmission    transmission;
        Speed           speed;
        Steering        steering;
};  

#endif
