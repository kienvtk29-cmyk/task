#pragma once
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
