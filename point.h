#pragma once
#include <iostream>

class Point
{
private:
    unsigned int x;
    unsigned int y;

public:
    Point();

    Point(
        unsigned int x,
        unsigned int y);

    unsigned int GetX() const;

    unsigned int GetY() const;

    Point operator +(unsigned int value) const;

    Point operator -(unsigned int value) const;

    bool operator ==(const Point& other) const;

    bool operator !=(const Point& other) const;

    friend std::ostream& operator <<(
        std::ostream& stream,
        const Point& point);

    friend std::istream& operator >>(
        std::istream& stream,
        Point& point);
};
