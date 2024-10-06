#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Node.hpp"
#include "Rail.hpp"
#include "Scheduler.hpp"

#define NODE "Node"
#define EVENT "Event"
#define RAIL "Rail"

enum class ParserType {
	NetworkData,
    TrainComposition
};


class Parser {
    public:
        virtual void parseData(const std::string& filepath) = 0;
        virtual ~Parser() {}
};


class NetworkParser: public Parser {
    private:
        float	parseDuration(const std::string& token);
    public:
        void parseData(const std::string& filepath);
};

class TrainCompositionParser: public Parser {
    private:
        float	parseDepartureHour(const std::string& token);
    public:
        void parseData(const std::string& filepath);
};
