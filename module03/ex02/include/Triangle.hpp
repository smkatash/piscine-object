#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <stdexcept>
#include "Shape.hpp"

class Triangle: public Shape {
    private:
        double  _a;
        double  _b;
        double  _c;
        double  get_semiparameter() const {
            return(_a + _b + _c) / 2;
        }

        double get_sqrt(double x) const {
            if (x <= 0) return 0;
            double guess = x / 2.0;
            double prev;
            do {
                prev = guess;
                guess = (guess + x / guess) / 2.0;
            } while (prev != guess);
            return guess;
        }
    public:
        Triangle(const double a_length, const double b_length, const double c_length) {
                if (a_length <= 0 && b_length <= 0 && c_length <= 0) {
                    throw std::out_of_range("Wrong input attributes!");
                }
                _a = a_length;
                _b = b_length;
                _c = c_length;
            }
        ~Triangle() {}
        double  get_area() const {
            double s = this->get_semiparameter();
            return (this->get_sqrt(s * (s - _a) * (s - _b) * (s - _c)));
        }
        double  get_perimeter() const {
            return (_a + _b + _c);
        }
};

#endif
