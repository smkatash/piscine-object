#include "PathFinder.hpp"
#include "TrainComposition.hpp"

PathFinder::PathFinder(): _algorithm(new DijkstraAlgorithm()) {}

PathFinder::~PathFinder() {
    if (this->_algorithm) {
        delete this->_algorithm;
    }
}

void    PathFinder::setNetwork(std::vector<Rail*>  network) {
    this->_algorithm->setNetwork(network);
}
void    PathFinder::setNodes(std::vector<Node*> nodes) {
    this->_algorithm->setNodes(nodes);
}

std::pair<std::vector<Rail*>, float> PathFinder::findShortestPath(TrainComposition* compostion) {
    std::vector<Rail*> routes = this->_algorithm->findShortestPath(compostion->getDepartureNode(), compostion->getArrivalNode());
    float distance = 0;
    for (Rail* rail: routes) {
        distance += rail->getLength();
    }
    return std::make_pair(routes, distance);
}

DijkstraAlgorithm::DijkstraAlgorithm() {}
DijkstraAlgorithm::~DijkstraAlgorithm() {}

void    DijkstraAlgorithm::setNetwork(std::vector<Rail*>  network) {
    this->_network = network;
}
void    DijkstraAlgorithm::setNodes(std::vector<Node*> nodes) {
    this->_nodes = nodes;
}

std::vector<Rail*>    DijkstraAlgorithm::findShortestPath(Node* start, Node* goal) {
    std::map<Node*, float>  dist;
    std::map<Node*, Node*>  prev;

    for (Node* node: this->_nodes) {
        dist.insert(std::make_pair(node, INFINITY));
        prev.insert(std::make_pair(node, nullptr));
    }
    dist.at(start) = 0;

    std::priority_queue<std::pair<float, Node*>, std::vector<std::pair<float, Node*> >, std::greater<std::pair<float, Node*> > > Q;
    Q.push(std::make_pair(0, start));

    while (!Q.empty()) {
        Node* currentNode = Q.top().second;
        float currentDist = Q.top().first;
        Q.pop();
        if (currentNode == goal) {
            break;
        }
        for (Rail* rail : this->_network) {
            Node* neighbor = rail->getOtherNode(currentNode);
            Node* departFrom = rail->getDepartureNode();
            if (neighbor && currentNode == departFrom) {
                float alt = currentDist + rail->getLength();
                if (alt < dist[neighbor]) {
                    dist[neighbor] = alt;
                    prev[neighbor] = currentNode;
                    Q.push(std::make_pair(alt, neighbor));
                }
            }
        }
    }
    std::vector<Rail*> path;
    Node* step = goal;
    while (step && prev[step]) {
        Node* previous = prev[step];
        for (Rail* rail : this->_network) {
            if ((rail->getOtherNode(previous) == step) || (rail->getOtherNode(step) == previous)) {
                path.push_back(rail);
                break;
            }
        }
        step = previous;
    }

    std::reverse(path.begin(), path.end());
    return path;
}
