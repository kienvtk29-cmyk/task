#include <iostream>
#include <cmath>
#include "Triangle.h"


/**
* @breaf считывает сторону треугольника с клавиатуры
* @param report - строка информации
* * @return считанное знаначение
*/
double getSide(std::string report = "");

/**
* @breaf точка входа в программу
* @return 0, если программа выполнена корректно
*/
int main()
{
    double side1 = getSide("Enter first side: ");
    double side2 = getSide("Enter second side: ");
    double side3 = getSide("Enter third side: ");
    Triangle myTriangle(side1, side2, side3);
    std::cout << "Perimetr is " << myTriangle.getPerimetr() << std::endl;
    std::cout << "Area is " << myTriangle.getArea() << std::endl;

    return 0;
}

double getSide(std::string report)
{
    std::cout << report << std::endl;
    double side = 0;
    std::cin >> side;
    if (std::cin.fail())
    {
        std::cout << "Error\n";
        exit(1);
    }
    return side;

}