#include "City.hpp"

City::City(std::string p_name): _name(p_name) {}

City::~City() {}

const std::string* City::getName() { return &this->_name; }
