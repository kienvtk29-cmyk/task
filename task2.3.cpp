#include<math.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * @brief Считывает целое число с клавиатуры
 * @return Введённое целое число
 * @note Если ввод некорректен, программа завершает работу
 */
int getValue();

/**
 * @brief Вычисляет сумму трёх чисел x, y и z
 * @param x Первое число
 * @param y Второе число
 * @param z Третье число
 * @return Сумма x + y + z
 */
double getsum(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()

{
	
	printf("enter first number ");
	double x = getValue();
	printf("enter second number ");
	double y = getValue();
	printf("enter third number ");
	double z = getValue();
	if (getsum(x, y, z) > 0)
		printf("The sum of x, y and z is positive %lf", getsum(x,y,z));
	else if (getsum(x, y, z) < 0)
		printf("The sum of x, y and z is negative %lf", getsum(x, y, z));
	else
		printf("The sum of x, y and z is zero");
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
double getsum(const double x, const double y, const double z)
{
	return x + y + z;
}




