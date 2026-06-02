#pragma once
#include <iostream>
#include <string>

class PlaneFigure
{
public:
    virtual ~PlaneFigure() = default;

    virtual std::string ToString() const = 0;

    virtual void Draw() const = 0;

    virtual void Read(std::istream& stream) = 0;
};

