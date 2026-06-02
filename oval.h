#pragma once
#include "PlaneFigure.h"
#include "Point.h"

#include <sstream>
#include <stdexcept>

class Oval final : public PlaneFigure
{
private:
    Point center;

    unsigned int radiusX;
    unsigned int radiusY;

    unsigned int maxResolution;

    void Validate() const;

public:
    Oval(
        const Point& center,
        unsigned int radiusX,
        unsigned int radiusY,
        unsigned int maxResolution);

    Oval(
        unsigned int x,
        unsigned int y,
        unsigned int radiusX,
        unsigned int radiusY,
        unsigned int maxResolution);

    std::string ToString() const override;

    void Draw() const override;

    void Read(std::istream& stream) override;

    static Oval ReadOval(
        std::istream& stream,
        unsigned int maxResolution);

    friend std::ostream& operator <<(
        std::ostream& stream,
        const Oval& oval);
};
