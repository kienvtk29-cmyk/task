#include<math.h>
#include<stdio.h>
/**
* @brief рассчитывает значение А
* @param x - значение x
* @param y - значение y
* @param z - значение z
* @return рассчитанное значение А
*/
double getA(const double x, const double y, const double z);
/**
* @brief рассчитывает значение В
* @param x - значение x
* @param y - значение y
* @param z - значение z
* @return рассчитанное значение В
*/
double getB(const double x, const double y, const double z);
int main()
{
	const double x = 0.5;
	const double y = 0.05;
	const double z = 0.7;
	printf("%lf\n", getA(x, y, z));
	printf("%lf", getB(x, y, z));

}
double getA(const double x, const double y, const double z)
{
	return pow(x, 2) * (x + 1) / (y - pow(sin(x + z), 2));
}
double getB(const double x, const double y, const double z)
{
	return sqrt(x * y / z) + pow(cos((pow((x + y), 2))), 2);
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	double x = 0.00;
	double dx = 0.1;
	double getA(const double x);
	double getA(const double x) {
		for (x = 0.00, x <= 1, x++0.1) {

		}
	}

	return 0;
}
