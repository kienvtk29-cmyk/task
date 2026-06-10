#pragma once

#include <string>

/**
 * @brief Абстрактный базовый класс плоской фигуры.
 */
class PlaneFigure
{
public:

    /**
     * @brief Преобразует объект в строку.
     *
     * @return Строковое представление объекта.
     */
    virtual std::string ToString() const = 0;

    /**
     * @brief Считывает данные фигуры из потока ввода.
     */
    virtual void Read() = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~PlaneFigure() = default;
};