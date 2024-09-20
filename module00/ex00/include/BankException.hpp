#include <iostream>
#include <exception>
#include <cstring>

class BankException : public std::exception {
private:
    std::string message;

public:
    BankException(const std::string& msg) : message(msg) {}
    BankException(const char* msg): message(msg) {}
    virtual ~BankException() throw() {}
    virtual const char* what() const throw() {
        return message.c_str();
    }
};