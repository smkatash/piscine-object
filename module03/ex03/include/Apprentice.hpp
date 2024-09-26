#ifndef APPRENTICE_HPP
#define APPRENTICE_HPP
#include "Employee.hpp"
#include "ISalariedEmployee.hpp"
#include "IStudyingEmployee.hpp"
#include <list>
#define SCHOOL_HOURS 4.00
#define WORK_HOURS 4.00

class Apprentice: public Employee, ISalariedEmployee, IStudyingEmployee {
    private:
       std::list<double> _non_working_hours;
       std::list<double> _school_hours;
       std::list<double> _school_hours_before_work;

    public:
        Apprentice(const std::string& name, const double hourly_value) 
            : Employee(name, hourly_value) {}
        ~Apprentice() {}
        double    execute_workday() {
            std::cout << this->_name << " is working." << std::endl;
            this->log_school_hours(SCHOOL_HOURS);
            double school_value = this->_hourly_value / 2;
            double school_hours_to_pay = (school_value * SCHOOL_HOURS) /  this->_hourly_value;
            std::cout << this->_name << " had " << SCHOOL_HOURS << " school hours today." << std::endl;
            return (WORK_HOURS - school_hours_to_pay);
        }
        void register_non_working_hours(double hour) {
            this->_non_working_hours.push_back(hour); 
        }

        void log_school_hours(double hour) {
            this->_school_hours.push_back(hour); 
        }
        void log_school_hours_before_work(double hour) {
            this->_school_hours_before_work.push_back(hour); 
        }

        double calculate_total_non_working_hours() const {
            double total_hours = 0;
            std::list<double>::const_iterator it = this->_non_working_hours.begin();
            for (; it != this->_non_working_hours.end(); ++it) {
                total_hours += *it;
            }
            return total_hours;
        }
        double calculate_total_school_hours() const {
            double total_hours = 0;
            std::list<double>::const_iterator it = this->_school_hours.begin();
            for (; it != this->_school_hours.end(); ++it) {
                total_hours += *it;
            }
            return total_hours;
        }
        
        void display_info() const {
            std::cout << "Student Worker" << std::endl;
            std::cout << "Total non working hours: " << calculate_total_non_working_hours() << std::endl;
            std::cout << "Total school hours: " << calculate_total_school_hours() << std::endl;
        }
        
};

#endif
