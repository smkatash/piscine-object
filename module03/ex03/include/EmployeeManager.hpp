#ifndef EMPLOYEE_MANAGER_HPP
#define EMPLOYEE_MANAGER_HPP
#include <set>
#include <map>
#include "Employee.hpp"

class EmployeeManager {
    private:
        std::set<Employee *>            _employees;
        std::map<Employee *, double>    _payroll_data;
    public:
        EmployeeManager() {};
        ~EmployeeManager() {};
        void add_employee(Employee* employee) {
            this->_employees.insert(employee);
            std::cout << *employee->get_name() << " with hourly value " << *employee->get_hourly_value() << "$ is hired.\n";
        }
        void remove_employee(Employee* employee) {
            std::set<Employee *>::iterator it = this->_employees.begin();
            for (; it != this->_employees.end(); ++it) {
                if (*it == employee) {
                    this->_employees.erase(employee);
                    std::cout << *employee->get_name() << " is released from the company.\n";
                    break;
                }
            }
        }
        void execute_workday() {
            std::set<Employee *>::iterator it = this->_employees.begin();
            for (; it != this->_employees.end(); ++it) {
                Employee* employee = *it;
                if (this->_payroll_data.find(employee) != this->_payroll_data.end()) {
                    double& hours = this->_payroll_data[employee];
                    hours += employee->execute_workday();
                } else {
                    this->_payroll_data[employee] = employee->execute_workday();
                }
            }
        }
        void calculate_payroll() {
            std::set<Employee *>::iterator it = this->_employees.begin();
            for (; it != this->_employees.end(); ++it) {
                Employee* employee = *it;
                if (this->_payroll_data.find(employee) != this->_payroll_data.end()) {
                    const double* value  = employee->get_hourly_value();
                    double worked_hours = this->_payroll_data[employee];
                    std::cout << *employee->get_name() << " should get: " << (*value) * worked_hours << "$.\n";
                }
            }
        }
};

#endif
