#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int getValue();
double getDouble();
double getSumN(const int n);
double getSumE(const double e);
double getRecurent(const int i);
void checkPositive(const double value);
void checkPositive(const double value) 
{
	if (value <= 0) 
	{
		printf("error \n");
		exit(1);
	}
}
int main()
{
	printf("type n:");
	int n = getValue();
	checkPositive(n);
	printf("type in e:");
	double e = getDouble();
	checkPositive(e);
	printf("sum %d number of sequences = %.4lf\n", n, getSumN(n));
	printf("sum of sequences more than number e = %.lf", e, getSumE(e));

	return 0;
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