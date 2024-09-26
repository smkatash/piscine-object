#ifndef IHOURLYEMPLOYEE_HPP
#define IHOURLYEMPLOYEE_HPP

class IHourlyEmployee {
    public:
        virtual void register_working_hours(double hour) = 0;
        virtual double calculate_total_hours() const = 0;
        virtual void display_info() const = 0;
        virtual ~IHourlyEmployee() {}
};

#endif
