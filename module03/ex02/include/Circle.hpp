#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <stdexcept>
#include "Shape.hpp"

class Circle: public Shape {
    private:
        double  _radius;
        double  _pi;
    public:
        Circle(const double radius) {
                if (radius <= 0) {
                    throw std::out_of_range("Wrong input attributes!");
                }
                _radius = radius;
                _pi = 3.14159265;
        }
        ~Circle() {}
        double  get_area() const {
           return _pi * _radius * _radius;
        }
        double  get_perimeter() const {
            return 2 * _pi * _radius;
        }
};

#endif
