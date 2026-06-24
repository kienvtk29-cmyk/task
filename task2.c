#include<math.h>
#include<stdio.h>
/**
 * @brief Вычисляет произведение A и n
 * @param A Число A
 * @param n Коэффициент n
 * @return Результат A * n
 */
double getSum1(const double A, const double n);

/**
 * @brief Вычисляет произведение A и 2n
 * @param A Число A
 * @param n Коэффициент n
 * @return Результат A * 2 * n
 */
double getSum2(const double A, const double n);

/**
 * @brief Вычисляет произведение A и 3n
 * @param A Число A
 * @param n Коэффициент n
 * @return Результат A * 3 * n
 */
double getSum3(const double A, const double n);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
	double A =0, n = 0;
	printf("enter your number ")s;
	scanf_s("%lf", &A);
	printf("enter coefficient ");
	scanf_s("%lf", &n);
	
	printf("n time %.2lf\n", getSum1(A,n));
	printf("2n time %.2lf\n", getSum2(A,n));
	printf("3n time %.2lf\n", getSum3(A, n));
	return 0;

}
double getSum1(const double A, const double n) {
	
	return A * n;
}
double getSum2(const double A, const double n) {
	
	return A * 2 * n;
}
double getSum3(const double A, const double n){

	
	return A * 3 * n;
}
