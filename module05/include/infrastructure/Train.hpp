#pragma once

#include "Speed.hpp"
#include "Node.hpp"

class Train {
    private:
        std::string _name;
        Speed       _speed;
        
    public:
        Train(std::string p_name, float p_maxAccelerationForce, float p_maxBrakeForce);
        ~Train();
        const std::string*   getName();
};
