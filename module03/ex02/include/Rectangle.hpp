#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <stdexcept>
#include "Shape.hpp"

class Rectangle: public Shape {
    private:
        double  _length;
        double  _width;
    public:
        Rectangle(const double length, const double width) {
                if (length <= 0 && width <= 0) {
                    throw std::out_of_range("Wrong input attributes!");
                }
                _length = length;
                _width = width;
            }
        ~Rectangle() {}
        double  get_area() const {
          return (_length * _width);
        }
        double  get_perimeter() const {
            return (2 * (_length + _width));
        }
};

#endif
