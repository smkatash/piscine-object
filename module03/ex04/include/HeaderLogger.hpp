#ifndef HEADERLOGGER_HPP
#define HEADERLOGGER_HPP
#include <iostream>
#include <ctime>
#include <string>

class HeaderLogger {
    private:
        std::string _title;

    public:
        HeaderLogger(const std::string &title) : _title(title) {};
        ~HeaderLogger() {};

        std::string    get_header() {
            return std::string("***" + this->_title + "***\n");
        }

        std::string get_timestamp() {
            std::time_t current_time = std::time(nullptr);
            return std::string(std::ctime(&current_time)) + "\n";
        }
};

#endif
