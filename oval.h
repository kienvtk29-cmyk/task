#pragma once

#include "PlaneFigure.h"
#include "Point.h"

#include <string>

/**
 * @brief Класс, представляющий овал на плоскости.
 */
class Oval : public PlaneFigure
{
private:

    /**
     * @brief Центр овала.
     */
    Point center;

    /**
     * @brief Горизонтальный радиус.
     */
    int radiusX;

    /**
     * @brief Вертикальный радиус.
     */
    int radiusY;

    /**
     * @brief Максимально допустимая координата.
     */
    int maxResolution;

public:

    /**
     * @brief Создает экземпляр класса Oval.
     *
     * @param center Центр овала.
     * @param radiusX Горизонтальный радиус.
     * @param radiusY Вертикальный радиус.
     * @param maxResolution Максимальное разрешение экрана.
     *
     * @throw std::invalid_argument Если параметры некорректны.
     */
    Oval(
        const Point& center,
        const int radiusX,
        const int radiusY,
        const int maxResolution);

    /**
     * @brief Возвращает строковое представление овала.
     *
     * @return Строковое представление объекта.
     */
    std::string ToString() const override;

    /**
     * @brief Считывает данные овала из стандартного потока ввода.
     */
    void Read() override;

    /**
     * @brief Считывает объект Oval из стандартного потока ввода.
     *
     * @return Новый объект Oval.
     */
    static Oval ReadFromStream();

    /**
     * @brief Выводит объект Oval в поток вывода.
     *
     * @param os Поток вывода.
     * @param oval Объект Oval.
     *
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(
        std::ostream& os,
        const Oval& oval);
};