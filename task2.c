#include<math.h>
#include<stdio.h>

double A, n;
double getSum1(const double A, const double n);
double getSum2(const double A, const double n);
double getSum3(const double A, const double n);
int main()
{

	printf("enter your number");
	scanf_s("%lf", &A);
	printf("enter coefficient");
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

