#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double getR(const double L, const double S, const long double p);
double L, S;
long double p = 2.8 * pow(10.0, -6.0);
void checkPositive(const double L, const double S);
void checkPositive(const double L, const double S)
{
	if (L <= 0 && S <= 0)
	{
		printf("error \n");
		exit(1);
	}
}
int main()
{
	printf("enter L:");
	scanf_s("%lf", &L);
	printf("enter S:");
	scanf_s("%lf", &S);
	checkPositive(L, S);
	printf("result R %.10lf", getR(L, S, p));
	return 0;
}
double getR(const double L, const double S, const long double p)
{
	return p * L / S;
}