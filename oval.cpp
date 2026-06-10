#include "Oval.h"

#include <sstream>
#include <stdexcept>

/**
 * @brief Реализация конструктора Oval.
 */
Oval::Oval(
    const Point& center,
    const int radiusX,
    const int radiusY,
    const int maxResolution)
    : center(center),
    radiusX(radiusX),
    radiusY(radiusY),
    maxResolution(maxResolution)
{
    if (radiusX <= 0)
    {
        throw std::invalid_argument(
            "Radius X must be positive.");
    }

    if (radiusY <= 0)
    {
        throw std::invalid_argument(
            "Radius Y must be positive.");
    }

    if (center.GetX() < 0 ||
        center.GetY() < 0)
    {
        throw std::invalid_argument(
            "Coordinates must be positive.");
    }

    if (center.GetX() > maxResolution ||
        center.GetY() > maxResolution)
    {
        throw std::invalid_argument(
            "Coordinates exceed screen resolution.");
    }
}

/**
 * @brief Формирует строковое представление объекта.
 */
std::string Oval::ToString() const
{
    std::ostringstream stream;

    stream
        << "Oval: center("
        << center.GetX()
        << ", "
        << center.GetY()
        << "), radiusX="
        << radiusX
        << ", radiusY="
        << radiusY;

    return stream.str();
}

/**
 * @brief Считывает данные овала.
 */
void Oval::Read()
{
    *this = ReadFromStream();
}

/**
 * @brief Создает объект Oval из потока ввода.
 */
Oval Oval::ReadFromStream()
{
    Point center;
    int radiusX;
    int radiusY;
    int resolution;

    std::cin
        >> center
        >> radiusX
        >> radiusY
        >> resolution;

    return Oval(
        center,
        radiusX,
        radiusY,
        resolution);
}

std::ostream& operator<<(
    std::ostream& os,
    const Oval& oval)
{
    os << oval.ToString();
    return os;
}