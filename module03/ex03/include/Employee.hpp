#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
#include <exception>
#define WORKDAY_HOUR 7.00

class Employee {
    protected:
        std::string     _name;
        double          _hourly_value;
    public:
        Employee(const std::string name, const double hourly_value) {
            if (hourly_value <= 0) {
                throw std::invalid_argument("Wrong hourly value!");
            }
            this->_name = name;
            this->_hourly_value = hourly_value;
        }
        const std::string* get_name() { return &this->_name; }
        const double* get_hourly_value() { return &this->_hourly_value; }
        virtual double    execute_workday() = 0;
        virtual ~Employee() {};
};

#endif



