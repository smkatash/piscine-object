#include "Rail.hpp"

Rail::Rail(Node* pointA, Node* pointB, float length, float maxSpeed):
    _nodeA(pointA), _nodeB(pointB), _length(length), _maxSpeedAllowed(maxSpeed) {}

Rail::~Rail() {}


float   Rail::getLength() {
    return this->_length;
}

float   Rail::getMaxSpeedAllowed() {
    return this->_maxSpeedAllowed;
}

Node* Rail::getOtherNode(Node* node) {
    if (node == _nodeA) return _nodeB;
    if (node == _nodeB) return _nodeA;
    return nullptr;
}

Node* Rail::getDepartureNode() { return _nodeA;}
Node* Rail::getArrivalNode() { return _nodeB; }
