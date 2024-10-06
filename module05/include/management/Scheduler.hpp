#pragma once
#include <vector>
#include "iostream"
#include "TrainComposition.hpp"
#include "Rail.hpp"
#include "Parser.hpp"
#include "Event.hpp"

class Scheduler {
    private:
        Scheduler() {};
        Scheduler(const Scheduler&) {};
        Scheduler& operator=(const Scheduler&) {};
        ~Scheduler() {}

        std::vector<Event*> _events;
        std::vector<Train*> _trains;
        std::vector<Rail*>  _network;
        std::vector<Node*>  _nodes;
        std::vector<TrainComposition*> _trainCompositions;
        Parser*             _dataParser;
        
        static Scheduler *_instance;
        friend Parser;
    public:
        static Scheduler *getInstance();
        void    addTrain(Train* train);
        void    addRail(Rail* rail);
        void    addNode(Node* node);
        void    addEvent(Event* event);
        void    addTrainComposition(TrainComposition* composition);

        Train*  getTrain(const std::string p_name);
        Node*   getNode(const std::string p_name);
        
};

Scheduler* Scheduler::_instance = nullptr;
