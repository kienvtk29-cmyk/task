#pragma once

#include <iostream>

/**
 * @brief Класс точки на плоскости.
 */
class Point
{
private:

    /**
     * @brief Координата X.
     */
    int x;

    /**
     * @brief Координата Y.
     */
    int y;

public:

    /**
     * @brief Создает экземпляр класса Point.
     *
     * @param x Координата X.
     * @param y Координата Y.
     */
    Point(
        const int x = 0,
        const int y = 0);

    /**
     * @brief Возвращает координату X.
     *
     * @return Координата X.
     */
    int GetX() const;

    /**
     * @brief Возвращает координату Y.
     *
     * @return Координата Y.
     */
    int GetY() const;

    /**
     * @brief Сравнивает две точки.
     *
     * @param other Другая точка.
     *
     * @return true, если точки равны.
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Проверяет точки на неравенство.
     *
     * @param other Другая точка.
     *
     * @return true, если точки различаются.
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Прибавляет число к координатам точки.
     *
     * @param value Значение для сложения.
     *
     * @return Новая точка.
     */
    Point operator+(const int value) const;

    /**
     * @brief Вычитает число из координат точки.
     *
     * @param value Значение для вычитания.
     *
     * @return Новая точка.
     */
    Point operator-(const int value) const;

    /**
     * @brief Выводит объект Point в поток.
     *
     * @param os Поток вывода.
     * @param point Объект Point.
     *
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(
        std::ostream& os,
        const Point& point);

    /**
     * @brief Считывает объект Point из потока.
     *
     * @param is Поток ввода.
     * @param point Объект Point.
     *
     * @return Поток ввода.
     */
    friend std::istream& operator>>(
        std::istream& is,
        Point& point);
};