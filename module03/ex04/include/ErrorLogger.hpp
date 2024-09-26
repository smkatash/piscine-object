#ifndef ERRORLOGGER_HPP
#define ERRORLOGGER_HPP
#include "ILogger.hpp"
#include "HeaderLogger.hpp"

class ErrorLogger: public ILogger {
    private:
        std::ostream* _out_stream;
        std::ofstream _file_stream; 
        HeaderLogger _header;
    public:
        ErrorLogger(const std::string& filename): _header(HeaderLogger("Error logger")) {
            this->_file_stream.open(filename);
            if (!this->_file_stream.is_open()) {
                throw std::runtime_error("Error: Could not create or open the file!");
            } else {
                this->_out_stream = &this->_file_stream;
            }
        }
        ErrorLogger(): _header(HeaderLogger("Error logger")) {
            this->_file_stream.open("file/output");
            if (!this->_file_stream.is_open()) {
                 throw std::runtime_error("Error: Could not create or open the file!");
            } else {
                this->_out_stream = &this->_file_stream;
            }
        }
        ErrorLogger(std::ostream& out_stream) 
        : _out_stream(&out_stream), _header(HeaderLogger("Error logger")) {}
        ~ErrorLogger() {
        if (this->_file_stream.is_open()) this->_file_stream.close();
        }

        void write(std::string message) {
           if (this->_out_stream->good()) {
            (*_out_stream) << message << std::endl;
            (*_out_stream) << this->_header.get_timestamp();
            } else {
                throw std::runtime_error("Operation failed. Check output streams");
            }
        }
};

#endif 
