#include "Graph.hpp"

Graph::Graph(float x, float y): size(x,y) {}
Graph::~Graph() {}

void    Graph::add_point(float x, float y) {
    if (x >= 0 && y >=0 && x < this->size.X && y < this->size.Y ) {
        this->points.push_back(Vector2(x,y));
        return ;
    }
    throw std::out_of_range("Out of Graph range");
}

void    Graph::add_point(Vector2& point) {
    if (point.X >= 0 && point.Y >=0 && point.X < this->size.X && point.Y < this->size.Y ) {
        this->points.push_back(point);
        return ;
    }
    throw std::out_of_range("Out of Graph range");
}

bool    Graph::pointExists(Vector2& point) {
    for (size_t i = 0; i < this->points.size(); i++) {
        if (point == points[i]) {
            return (true);
        }
    }
    return (false);
}

void Graph::output_graph() {
    for (float y = size.Y - 1; y >= 0; y--) {
        std::cout << std::setw(2) << y << " ";
        for (float x = 0; x < size.X; x++) {
            Vector2 point(x, y);
            if (this->pointExists(point)) {
                std::cout << "X "; 
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (float x = 0; x < size.X; x++) {
        std::cout << std::setw(2) << x;
    }
    
}
