#include "Triangle.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include <iostream>

void get_data(Shape *shape) {
    std::cout << "Area: " << shape->get_area() << std::endl;
    std::cout << "Perimeter: " <<shape->get_perimeter() << std::endl;
}

int main()
{
    Rectangle rectangle(10, 12);
    Triangle triangle(4, 4, 6);
    Circle circle(4);
    get_data(&rectangle);
    get_data(&triangle);
    get_data(&circle);
}
