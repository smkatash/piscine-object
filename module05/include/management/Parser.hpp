#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Scheduler.hpp"
#include "TrainComposition.hpp"

#define NODE "Node"
#define EVENT "Event"
#define RAIL "Rail"
#define DEFAULT_SPEED 120.f

enum ParserType {
	NetworkData,
    TrainData
};

class TrainComposition;

class Parser {
    public:
        virtual void parseData(const std::string& filepath) = 0;
        virtual ~Parser() {}
};


class NetworkParser: public Parser {
    private:
        bool    isNumber(const std::string& s);
        bool    isSubstringAtEndOfLine(const std::string& line, const std::string& substring);
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
