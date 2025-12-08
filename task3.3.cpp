#include<math.h>
#include<stdio.h>
#include<stdlib.h>
double getValue(const double x);
double getSum(const double x, const double n);

double getValue(const double x) {
	return 0.5 * log(x);
}
double getSum(const double x, const double n) {
    double t = (x - 1.0) / (x + 1.0);
    double t_squared = t * t;
    double term = t;           
    double total = term;
    double eps = pow(10, - 4);
    for (int n = 1; fabs(term) >= eps; n++) {
        term *= t_squared * (2 * n - 1) / (2 * n + 1);
        total += term;

    }
    return total;
}
int main() {
    double x;
    

    printf(" x\t\t f(x)\t\t Series Sum\n");

    for (x = 0.2; x <= 1; x += 0.1) {
        int n = 1;
        double fx = getValue(x);
        double sum = getSum(x, n);

        printf("%.1f\t\t%.4f\t\t%.4f\n", x, fx, sum);
    }

    return 0;



}