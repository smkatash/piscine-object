#pragma once
#include "Train.hpp"

class TrainComposition {
    private:
        Train*      _train;
        Node*       _departFrom;
        Node*       _arriveAt;
        float       _departureTime;
    
    public: 
        TrainComposition(Train* train, Node* depart, Node* arrive, float departAt);
        ~TrainComposition();
        Train*  getTrain();
        Node*   getDepartureNode();
        Node*   getArrivalNode();
        float   getDepartureTime();
};
