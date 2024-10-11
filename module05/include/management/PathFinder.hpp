#pragma once

#include "Rail.hpp"
#include <map>
#include <queue>

class TrainComposition;

class Algorithm {
    public:
        virtual std::vector<Rail*> findShortestPath(Node* start, Node* goal) = 0;
        virtual void    setNetwork(std::vector<Rail*>  network) = 0;
        virtual void    setNodes(std::vector<Node*> nodes) = 0;
        virtual ~Algorithm() {}
};

class DijkstraAlgorithm: public Algorithm {
    private:
        std::vector<Rail*>  _network;
        std::vector<Node*> _nodes;
    public:
        DijkstraAlgorithm();
        ~DijkstraAlgorithm();
        std::vector<Rail*>   findShortestPath(Node* start, Node* goal);
        void    setNetwork(std::vector<Rail*>  network);
        void    setNodes(std::vector<Node*> nodes);
};

class PathFinder {
    private:
        Algorithm*          _algorithm;

    public:
        PathFinder();
        ~PathFinder();
        void    setNetwork(std::vector<Rail*>  network);
        void    setNodes(std::vector<Node*> nodes);
        std::pair<std::vector<Rail*>, float>  findShortestPath(TrainComposition* compostion);
};
