#include "Vector2.hpp"
#include <vector>
#include <exception>
#include <iostream>
#include <iomanip>

class Graph {
    private:
        Vector2 size;
        std::vector<Vector2> points;
        bool    pointExists(Vector2& point);
    public:
        Graph(float x, float y);
        ~Graph();
        void    add_point(float x, float y);
        void    add_point(Vector2& point);
        void    output_graph();
};