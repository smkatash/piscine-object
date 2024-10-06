#pragma once

#include <iostream>

class City {
    protected:
        std::string _name;

    public:
        City(std::string p_name);
        virtual ~City();
        const std::string* getName();
};
