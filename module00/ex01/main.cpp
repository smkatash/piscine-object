#include "Graph.hpp"


int main() {
    Graph graph(6,6);
    Vector2 p1(0,0);
    Vector2 p2(2,2);
    Vector2 p3(4,2);
    Vector2 p4(2,4);
    try {
        graph.add_point(p1);
        graph.add_point(p2);
        graph.add_point(p3);
        graph.add_point(p4);
        graph.add_point(1,1);

        graph.output_graph();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

}