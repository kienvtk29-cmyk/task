#include "Point.h"

using namespace std;

Point::Point()
    : x(0), y(0)
{
}

Point::Point(
    unsigned int x,
    unsigned int y)
    : x(x), y(y)
{
}

unsigned int Point::GetX() const
{
    return x;
}

unsigned int Point::GetY() const
{
    return y;
}

Point Point::operator +(unsigned int value) const
{
    return Point(x + value, y + value);
}

Point Point::operator -(unsigned int value) const
{
    return Point(x - value, y - value);
}

bool Point::operator ==(const Point& other) const
{
    return x == other.x &&
        y == other.y;
}

bool Point::operator !=(const Point& other) const
{
    return !(*this == other);
}

ostream& operator <<(
    ostream& stream,
    const Point& point)
{
    stream
        << "("
        << point.x
        << ", "
        << point.y
        << ")";

    return stream;
}

istream& operator >>(
    istream& stream,
    Point& point)
{
    stream >> point.x >> point.y;

    return stream;
}