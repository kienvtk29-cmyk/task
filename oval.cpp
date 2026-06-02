#include "oval.h"
using namespace std;

void Oval::Validate() const
{
    if (radiusX == 0 || radiusY == 0)
    {
        throw invalid_argument(
            "Radius must be greater than zero.");
    }

    if (center.GetX() > maxResolution ||
        center.GetY() > maxResolution)
    {
        throw out_of_range(
            "Point exceeds screen resolution.");
    }
}

Oval::Oval(
    const Point& center,
    unsigned int radiusX,
    unsigned int radiusY,
    unsigned int maxResolution)
    : center(center),
    radiusX(radiusX),
    radiusY(radiusY),
    maxResolution(maxResolution)
{
    Validate();
}

Oval::Oval(
    unsigned int x,
    unsigned int y,
    unsigned int radiusX,
    unsigned int radiusY,
    unsigned int maxResolution)
    : center(x, y),
    radiusX(radiusX),
    radiusY(radiusY),
    maxResolution(maxResolution)
{
    Validate();
}

string Oval::ToString() const
{
    ostringstream stream;

    stream
        << "Oval: center = "
        << center
        << ", radiusX = "
        << radiusX
        << ", radiusY = "
        << radiusY;

    return stream.str();
}

void Oval::Draw() const
{
    cout << ToString() << endl;
}

void Oval::Read(istream& stream)
{
    stream >> center;
    stream >> radiusX;
    stream >> radiusY;

    Validate();
}

Oval Oval::ReadOval(
    istream& stream,
    unsigned int maxResolution)
{
    Point point;

    unsigned int radiusX;
    unsigned int radiusY;

    stream >> point;
    stream >> radiusX;
    stream >> radiusY;

    return Oval(
        point,
        radiusX,
        radiusY,
        maxResolution);
}

ostream& operator <<(
    ostream& stream,
    const Oval& oval)
{
    stream << oval.ToString();

    return stream;
}