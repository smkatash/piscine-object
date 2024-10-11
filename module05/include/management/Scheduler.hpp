#pragma once
#include <vector>
#include <sstream>
#include "iostream"
#include "Event.hpp"
#include "PathFinder.hpp"
#include "FileLogger.hpp"
#include "TrainComposition.hpp"

class Rail; 
class Node; 
class Train; 
class TrainComposition;
class Event;

class Scheduler {
    private:
        Scheduler() {};
        Scheduler(const Scheduler&);

        std::vector<Rail*>  _network;
        std::vector<Node*>  _nodes;
        std::vector<Event*> _events;
        std::vector<Train*> _trains;
        std::vector<TrainComposition*> _trainCompositions;

        static Scheduler            *_instance;
        std::string stateToString(State state);
        PathFinder                  _pathFinder;
        FileLogger                  _logger;
        bool    isEventOccurred(float probability);
    public:
        ~Scheduler() {};
        static Scheduler *getInstance();
        void    addTrain(Train* train);
        void    addRail(Rail* rail);
        void    addNode(Node* node);
        void    addEvent(Event* event);
        void    addTrainComposition(TrainComposition* composition);

        Train*                  getTrain(const std::string p_name);
        Node*                   getNode(const std::string p_name);
        std::vector<Rail*>      getNetwork();
        std::vector<Node*>      getAllNodes();
        void                    renderPath();
        std::map<Rail*, float>  detectEventsOnRail(std::vector<Rail*> routes);
        
        void                    logTrainStatus(float hour, Rail* rail, float totalDistance, Speed speed);
        void                    logTrainNode(size_t currentNode, size_t totalNodeCount);
        void                    logDelayEvent(float delay);
        void                    logEstimatedTravelTime(float hour);
        void debug();
};
