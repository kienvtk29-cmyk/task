#include<stdio.h>
#include<math.h>
#include <stdlib.h>

/**
 * @brief Проверяет, что значение положительное
 * @param value Значение для проверки
 * @note Если value <= 0, программа завершает работу
 */
void checkPositive(const double value);

/**
 * @brief Считывает целое число с клавиатуры
 * @return Введённое значение типа int
 * @note Если ввод некорректен, программа завершает работу
 */
int getValue();

/**
 * @brief Считывает число типа double с клавиатуры
 * @return Введённое значение типа double
 * @note Если ввод некорректен, программа завершает работу
 */
double getDouble();

/**
 * @brief Вычисляет сумму первых n членов последовательности
 * @param n Количество членов последовательности
 * @return Сумма первых n членов
 */
double getSumN(const int n);

/**
 * @brief Вычисляет сумму членов последовательности, пока абсолютное значение текущего члена больше e
 * @param e Пороговое значение
 * @return Сумма членов последовательности, удовлетворяющих условию
 */
double getSumE(const double e);

/**
 * @brief Вычисляет рекуррентный множитель для последовательности
 * @param i Номер члена последовательности
 * @return Значение рекуррентного множителя
 */
double getRecurent(const int i);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
	printf("type n:");
	int n = getValue();
	checkPositive(n);
	printf("type in e:");
	double e = getDouble();
	checkPositive(e);
	printf("sum %d number of sequences = %.4lf\n", n, getSumN(n));
	printf("sum of sequences more than number e = %lf is %lf", e, getSumE(e));

	return 0;
}
void checkPositive(const double value)
{
	if (value <= 0)
	{
		printf("error \n");
		exit(1);
	}
}
int getValue()

{
	int value = 0;
	if (!scanf_s("%d", &value)) {
		printf("error\n");
		exit(1);
	}
	return value;
}
double getSumN(const int n)
{
	double current = 1;
	double result = current; 
	

	for (int i = 1; i < n; i++) {
		current *= getRecurent(i);
		result += current;
	}
	return result;
}
double getRecurent(const int i)
{
	return  - 1.0 / i / (1 + i);
}
double getDouble() {
	double value = 0;
	if (!scanf_s("%lf", &value)) {
		printf("error\n");
		exit(1);
	}
	return value;
}
double getSumE(const double e) 
{
	double current = -1;
	double result = 0;
	for (int i = 1; fabs(current) > e; i++) {
		result += current;
		current *= getRecurent(i);
		
	}
	return result;
}
