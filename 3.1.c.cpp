#include<stdio.h>
#include<math.h>
#include <stdlib.h>

/**
 * @brief Считывает число типа double с клавиатуры
 * @return Введённое значение
 * @note Если ввод некорректен, программа завершает работу
 */
double getValue();

/**
 * @brief Вычисляет значение функции y = sqrt(1 - start) - cos(sqrt(1 - start))
 * @param start Начальная точка x
 * @param end Конечная точка x (не используется в вычислениях, только для проверки)
 * @return Значение функции y
 * @note Если 1 - start < 0 и 1 - end < 0, программа завершает работу с ошибкой
 */
double getA(const double start, const double end);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    printf("enter starting point = ");
    double start = getValue();
    printf("enter ending point = ");
    double end = getValue();
    printf("enter stepping point = ");
    double step = getValue();
    for (start; start <= end; start+=step) {

        double y = getA(start, end);
        printf("x = %.1f\t y = %.6lf\n", start, y);
    }

    return 0;
}

double getValue()

{
    double value = 0;
    if (!scanf_s("%lf", &value)) {
        printf("error\n");
        exit(1);
    }
    return value;
}
double getA(const double start, const double end)
{
    if (1 - start < 0 || start > end ) {
        printf("there is no solution");
        exit(1);
        return 0; 
    }
    else {
        double y = sqrt(1 - start) - cos(sqrt(1 - start));
        return y;
    }
}
