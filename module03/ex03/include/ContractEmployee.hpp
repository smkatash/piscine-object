#ifndef CONTRACTEMPLOYEE_HPP
#define CONTRACTEMPLOYEE_HPP
#include "Employee.hpp"
#include "ISalariedEmployee.hpp"
#include <list>
#define NON_WORKING_HOURS 2.00

class ContractEmployee: public Employee, ISalariedEmployee {
    private:
       std::list<double> _non_working_hours;
    public:
        ContractEmployee(const std::string& name, const double hourly_value) 
            : Employee(name, hourly_value) {}
        ~ContractEmployee() {}
        
        double    execute_workday() {
            std::cout << this->_name << " is working." << std::endl;
            register_non_working_hours(NON_WORKING_HOURS);
            std::cout << this->_name << " did not work " << NON_WORKING_HOURS << " hours today." << std::endl;
            return (WORKDAY_HOUR - NON_WORKING_HOURS);
        }
        
        void register_non_working_hours(double hour) {
            this->_non_working_hours.push_back(hour); 
        }

        double calculate_total_non_working_hours() const {
            double total_hours = 0;
            std::list<double>::const_iterator it = this->_non_working_hours.begin();
            for (; it != this->_non_working_hours.end(); ++it) {
                total_hours += *it;
            }
            return total_hours;
        }
        
        void display_info() const {
            std::cout << "Contract Worker" << std::endl;
            std::cout << "Total non working hours: " << calculate_total_non_working_hours() << std::endl;
        }
};

#endif
