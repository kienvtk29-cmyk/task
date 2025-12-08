#include<math.h>
#include<stdio.h>
#include<stdlib.h>
double x, y, z;
double getsum(const double x, const double y, const double z);
double getsum(const double x, const double y, const double z)
{
	return x + y + z;
}
int main() 

{
	printf("enter first number ");
	scanf_s("%lf", &x);
	printf("enter second number ");
	scanf_s("%lf", &y);
	printf("enter third number ");
	scanf_s("%lf",&z);
	if (getsum(x, y, z) > 0)
		printf("The sum of x, y and z is positive %lf", getsum(x,y,z));
	else if (getsum(x, y, z) < 0)
		printf("The sum of x, y and z is negative %lf", getsum(x, y, z));
	else
		printf("The sum of x, y and z is zero");
	return 0;
}
