#include <iostream>

#include "Oval.h"

/**
 * @brief Точка входа в программу.
 *
 * Демонстрирует работу класса Oval.
 *
 * @return Код завершения программы.
 */
int main()
{
    try
    {
        Oval oval(
            Point(400, 300),
            150,
            80,
            1920);

        std::cout
            << oval
            << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout
            << exception.what()
            << std::endl;
    }

    return 0;
}