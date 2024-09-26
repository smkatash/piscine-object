#ifndef ISALARIEDEMPLOYEE_HPP
#define ISALARIEDEMPLOYEE_HPP

class ISalariedEmployee {
    public:
        virtual void register_non_working_hours(double hour) = 0;
        virtual double calculate_total_non_working_hours() const = 0;
        virtual void display_info() const = 0;
        virtual ~ISalariedEmployee() {}
};

#endif
