#pragma once
#include "TrainComposition.hpp"

TrainComposition::TrainComposition(Train* train, Node* depart, Node* arrive, float departAt): 
    _train(train), _departFrom(depart), _arriveAt(arrive), _departureTime(departAt) {}

TrainComposition::~TrainComposition() {}

Train*  TrainComposition::getTrain() { return this->_train; }
Node*   TrainComposition::getDepartureNode() { return this->_departFrom; }
Node*   TrainComposition::getArrivalNode() { return this->_arriveAt; }
float   TrainComposition::getDepartureTime() { return this->_departureTime; }
