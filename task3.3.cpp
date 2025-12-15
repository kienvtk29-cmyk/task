#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief Считывает число типа double с клавиатуры
 * @return Введённое значение
 * @note Если ввод некорректен, программа завершает работу
 */
double getValue();

/**
 * @brief Вычисляет исходное значение функции f(x) = 0.5 * ln(x)
 * @param start Значение x
 * @return Значение функции f(x)
 */
double getoriginValue(const double start);

/**
 * @brief Вычисляет сумму ряда для приближённого вычисления 0.5 * ln(x)
 * @param start Значение x
 * @param n Начальный номер члена ряда (обычно 1)
 * @return Значение суммы ряда
 * @note Суммирование продолжается до достижения точности eps = 10^-4
 */
double getSum(const double start, const double n);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() {
    
    printf("enter starting point x = ");
    double start = getValue();
    printf("enter ending point x = ");
    double end = getValue();
    printf("enter stepping point = ");
    double step = getValue();

    printf(" x\t\t f(x)\t\t Series Sum\n");

    for (start; start <= end; start += step) {
        int n = 1;
        double fx = getoriginValue(start);
        double sum = getSum(start, n);

        printf("%.1f\t\t%.4f\t\t%.4f\n", start, fx, sum);
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
double getoriginValue(const double start) {
    return 0.5 * log(start);
}
double getSum(const double start, const double n) {
    double t = (start - 1.0) / (start + 1.0);
    double t_squared = t * t;
    double term = t;
    double total = term;
    double eps = pow(10, -4);
    for (int n = 1; fabs(0.5 * log(start) - total) >= eps; n++) {
        term *= t_squared * (2 * n - 1) / (2 * n + 1);
        total += term;

    }
    return total;
}
