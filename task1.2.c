#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>

double getSide(const double a, const double b, const double  t);
double getS(const double a, const double b,  const double  t);
void checkPositive(const double a, const double b);
double getR(const double a, const double b, const double  t);
void checkPositive(const double a, const double b)
{
	if (a <= 0 && b <= 0)
	{
		printf("error \n");
		exit(1);
	}
}
int main()
{
	double pi = atan(1) * 4;
	double a, b, c;
	printf("enter first side\n");
	scanf_s("%lf", &a);
	printf("enter sencond side\n");
	scanf_s(" %lf", &b);
	checkPositive(a, b);
	printf("enter corner\n");
	scanf_s("%lf", &c);
	double t = c * pi / 180;
	printf("the third side is %lf\n", getSide(a,b,t ));
	printf("the square is %lf\n", getS(a,b,t));
	printf("the R is %lf\n", getR(a, b, t));
	return 0;
}

double getSide(const double a, double b, double  t)
{
	return sqrt((pow(a, 2) + pow(b, 2) - 2 * a * b * cos(t)));
}
double getS(const  double a, double b, double  t)
{
	return (1 *1.0 / 2) * a * b * sin(t);
}
double getR(const double a, const double b, const double  t)
{
	return getSide(a, b, t) / (2 * sin(t));
}


