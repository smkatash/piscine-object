#include "Event.hpp"

Event::Event(std::string p_name, float p_probability, float p_duration, Node* node):
    _eventName(p_name), _probability(p_probability), _duration(p_duration), _location(node) {}

Event::~Event() {}

Node* Event::getLocation() {
    return this->_location;
}
