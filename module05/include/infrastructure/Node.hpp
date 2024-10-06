#pragma once

#include "City.hpp"

class Node: public City {
    public:
        Node(std::string p_name): City(p_name){}
        ~Node() {}
};
