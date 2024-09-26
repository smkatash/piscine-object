#ifndef ISTUDYINGEMPLOYEE_HPP
#define ISTUDYINGEMPLOYEE_HPP

#include "ISalariedEmployee.hpp"

class IStudyingEmployee {
    public:
        virtual void log_school_hours(double hour) = 0;
        virtual void log_school_hours_before_work(double hour) = 0;
        virtual double calculate_total_non_working_hours() const = 0;
        virtual double calculate_total_school_hours() const = 0;
        virtual void display_info() const = 0;
        virtual ~IStudyingEmployee() {}
        
};


#endif
