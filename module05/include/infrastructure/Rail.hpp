#pragma once

#include "Node.hpp"

class Rail {
    private:
        Node*   _nodeA;
        Node*   _nodeB;
        float   _length;

    public:
        Rail(Node* pointA, Node* pointB, float length);
        ~Rail();
        float   getLength();
};