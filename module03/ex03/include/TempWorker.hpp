#ifndef TEMPWORKER_HPP
#define TEMPWORKER_HPP
#include "Employee.hpp"
#include "IHourlyEmployee.hpp"
#include <list>

class TempWorker: public Employee, IHourlyEmployee {
    private:
       std::list<double> _working_hours;
    public:
        TempWorker(const std::string& name, const double hourly_value) 
            : Employee(name, hourly_value) {}
        ~TempWorker() {}

        double    execute_workday() {
            std::cout << this->_name << " is working." << std::endl;
            register_working_hours(WORKDAY_HOUR);
            std::cout << this->_name << " worked " << WORKDAY_HOUR << " hours today." << std::endl;
            return (WORKDAY_HOUR);
        }

        void register_working_hours(double hour) {
            this->_working_hours.push_back(hour); 
        }

        double calculate_total_hours() const {
            double total_hours = 0;
            std::list<double>::const_iterator it = this->_working_hours.begin();
            for (; it != this->_working_hours.end(); ++it) {
                total_hours += *it;
            }
            return total_hours;
        }
        
        void display_info() const {
            std::cout << "Temporary Worker" << std::endl;
            std::cout << "Total working hours: " << calculate_total_hours() << std::endl;
        }
};

#endif
