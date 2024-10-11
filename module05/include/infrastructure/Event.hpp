#pragma once

#include "Node.hpp"
#include <iostream>

enum EventType {
	PassengersDiscomfort,
    Riot
};

class Event {
    private:
        std::string _eventName;
        float   _probability;
        float   _duration;
        Node*   _location;
    public:
        Event(std::string p_name, float p_probability, float p_duration, Node* node);
        ~Event();
        Node* getLocation();
        std::string getEventName();
        float getProbability();
        float getDuration();

};
