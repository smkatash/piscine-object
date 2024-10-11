#pragma once
#include <iostream>
#include <fstream>
#include <exception>

class ILogger {
    public:
        virtual void write(std::string) = 0;
        virtual ~ILogger() {}
};  

