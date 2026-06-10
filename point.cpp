#include "Point.h"

/**
 * @brief Реализация конструктора класса Point.
 */
Point::Point(
    const int x,
    const int y)
    : x(x),
    y(y)
{
}

/**
 * @brief Возвращает координату X.
 */
int Point::GetX() const
{
    return x;
}

/**
 * @brief Возвращает координату Y.
 */
int Point::GetY() const
{
    return y;
}

/**
 * @brief Сравнение двух точек.
 */
bool Point::operator==(const Point& other) const
{
    return x == other.x &&
        y == other.y;
}

/**
 * @brief Проверка на неравенство.
 */
bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

/**
 * @brief Сложение точки и числа.
 */
Point Point::operator+(const int value) const
{
    return Point(x + value, y + value);
}

/**
 * @brief Вычитание числа из точки.
 */
Point Point::operator-(const int value) const
{
    return Point(x - value, y - value);
}

std::ostream& operator<<(
    std::ostream& os,
    const Point& point)
{
    os << point.x << " "
        << point.y;

    return os;
}

std::istream& operator>>(
    std::istream& is,
    Point& point)
{
    is >> point.x
        >> point.y;

    return is;
}