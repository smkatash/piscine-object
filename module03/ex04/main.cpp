#include "ErrorLogger.hpp"
#include "FileLogger.hpp"


int main() {
    ErrorLogger defaultLogger;  
    ErrorLogger e_logger(std::cerr);

    FileLogger file_logger("file/file.log");
    FileLogger out_logger(std::cout);

    std::vector<ILogger*> loggers;
    loggers.push_back(&defaultLogger);
    loggers.push_back(&e_logger);
    loggers.push_back(&file_logger);
    loggers.push_back(&out_logger);
    std::vector<ILogger*>::iterator it = loggers.begin();

    for (; it != loggers.end(); ++it) {
        (*it)->write("Some log!");
    }

}
