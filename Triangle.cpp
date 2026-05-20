#include <Iostream>
#include "Triangle.h"

Triangle::Triangle(const double side1, const double side2, const double side3)
{
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 >= side2 + side3 ||
        side2 >= side1 + side3 || side3 >= side2 + side1)
    {
        std::cout << "Error. Sides have to be positive\n";
        exit(1);
    }
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

double Triangle::getPerimetr() const
{
    return side1 + side2 + side3;
}

double Triangle::getArea() const
{
    double p = getPerimetr() / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}