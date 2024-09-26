#ifndef ILOGGER_HPP
#define ILOGGER_HPP
#include <iostream>
#include <fstream>
#include <exception>

class ILogger {
    public:
        virtual void write(std::string) = 0;
        virtual ~ILogger() {}
};  

#endif
