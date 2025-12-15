#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * @brief Проверяет, что стороны треугольника положительные
 * @param a Первая сторона
 * @param b Вторая сторона
 * @note Если обе стороны меньше или равны нулю, программа завершает работу с ошибкой
 */
void checkPositive(const double a, const double b);

/**
 * @brief Вычисляет третью сторону треугольника по формуле косинусов
 * @param a Первая сторона
 * @param b Вторая сторона
 * @param t Угол между сторонами a и b в радианах
 * @return Значение третьей стороны
 */
double getSide(const double a, const double b, const double t);

/**
 * @brief Вычисляет площадь треугольника по формуле площади через две стороны и угол
 * @param a Первая сторона
 * @param b Вторая сторона
 * @param t Угол между сторонами a и b в радианах
 * @return Площадь треугольника
 */
double getS(const double a, const double b, const double t);

/**
 * @brief Вычисляет радиус описанной окружности треугольника
 * @param a Первая сторона
 * @param b Вторая сторона
 * @param t Угол между сторонами a и b в радианах
 * @return Радиус описанной окружности
 */
double getR(const double a, const double b, const double t);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
	double a = 0 , b =  0, c=0;
	printf("enter first side\n");
	scanf_s("%lf", &a);
	printf("enter sencond side\n");
	scanf_s(" %lf", &b);
	checkPositive(a, b);
	printf("enter corner\n");
	scanf_s("%lf", &c);
	double t = c * M_PI / 180.0;
	printf("the third side is %lf\n", getSide(a,b,t ));
	printf("the square is %lf\n", getS(a,b,t));
	printf("the R is %lf\n", getR(a, b, t));
	return 0;
}
void checkPositive(const double a, const double b)
{
	if (a <= 0 && b <= 0)
	{
		printf("error \n");
		exit(1);
	}
}
double getSide(const double a, const double b,const double  t)
{
	return sqrt((pow(a, 2) + pow(b, 2) - 2 * a * b * cos(t)));
}
double getS(const  double a,const double b,const double  t)
{
	return (1 *1.0 / 2) * a * b * sin(t);
}
double getR(const double a, const double b, const double  t)
{
	return getSide(a, b, t) / (2 * sin(t));
}


