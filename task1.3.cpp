#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/**
 * @brief Проверяет, что длина и площадь положительные
 * @param L Длина
 * @param S Площадь
 * @note Если хотя бы одно значение <= 0, программа завершает работу с ошибкой
 */
void checkPositive(const double L, const double S);

/**
 * @brief Вычисляет сопротивление R по формуле R = p * L / S
 * @param L Длина проводника
 * @param S Площадь поперечного сечения проводника
 * @param p Удельное сопротивление материала
 * @return Значение сопротивления R
 */
double getR(const double L, const double S, const long double p);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
	double L =0, S = 0;
	long double p = 2.8 * pow(10.0, -6.0);
	printf("enter L:");
	scanf_s("%lf", &L);
	printf("enter S:");
	scanf_s("%lf", &S);
	checkPositive(L, S);
	printf("result R %.10lf", getR(L, S, p));
	return 0;
}
void checkPositive(const double L, const double S)
{
	if (L <= 0 && S <= 0)
	{
		printf("error \n");
		exit(1);
	}
}
double getR(const double L, const double S, const long double p)
{
	return p * L / S;
}
