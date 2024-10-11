#pragma once

#include "Node.hpp"

class Rail {
    private:
        Node*   _nodeA;
        Node*   _nodeB;
        float   _length;
        float   _maxSpeedAllowed;

    public:
        Rail(Node* pointA, Node* pointB, float length, float maxSpeed);
        ~Rail();
        float   getLength();
        float   getMaxSpeedAllowed();
        Node* getOtherNode(Node* node);
        Node* getDepartureNode();
        Node* getArrivalNode();
};
