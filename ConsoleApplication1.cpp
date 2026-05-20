#include <iostream>
#include <cmath>
/**
 * @breaf класс треугольник
 */
class Triangle
{
private:
    /**
    * @breaf первая сторона треугольника
    */
    double side1;
    /**
    * @breaf вторая сторона треугольника
    */

    double side2;
    /**
    * @breaf третья сторона треугольника
    */
    double side3;
public:

    /**
    * @breaf конструктор
    * @param side1 - первая сторона треугольника
    * @param side2 - вторая сторона треугольника
    * @param side3 - третья сторона треугольника
    */
    Triangle(const double side1, const double side2, const double side3);

    /**
   * @breaf Рассчет периметра
   * @return рассчитанное знаначение
   */
    double getPerimetr() const;

    /**
    * @breaf Рассчет площади треугольника
    * @return рассчитанное знаначение
    */
    double getArea() const;
};


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