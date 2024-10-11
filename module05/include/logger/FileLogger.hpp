#pragma once
#include "ILogger.hpp"
#include <iostream>

class FileLogger: public ILogger {
    private:
        std::ostream* _out_stream;
        std::ofstream _file_stream; 
    public:
        FileLogger() 
        : _out_stream(&std::cout) {}
        ~FileLogger() {}

        void setLogFile(const std::string& filename) {
            this->_file_stream.close();
            this->_file_stream.open(filename);
            if (!this->_file_stream.is_open()) {
                throw std::runtime_error("Error: Could not create or open the file!");
            } else {
                this->_out_stream = &this->_file_stream;
            }
        }
        void write(std::string message) {
            if (!this->_out_stream->good()) {
                if (this->_out_stream->fail()) {
                    throw std::runtime_error("Stream failbit set: Logical error (e.g., bad format)");
                } else if (this->_out_stream->bad()) {
                    throw std::runtime_error("Stream badbit set: Read/write error on i/o operation");
                } else if (this->_out_stream->eof()) {
                    throw std::runtime_error("Stream eofbit set: End of file reached");
                } else {
                    throw std::runtime_error("Stream is not in a good state");
                }
            } else {
                (*_out_stream) << message << std::endl;
            }
        }
};
