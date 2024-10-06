#include "Rail.hpp"

Rail::Rail(Node* pointA, Node* pointB, float length):
    _nodeA(pointA), _nodeB(pointB), _length(length){}

Rail::~Rail() {}


float   Rail::getLength() {
    return this->_length;
}
