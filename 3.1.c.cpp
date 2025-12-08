#include<stdio.h>
#include<math.h>



double getA(const double x);

int main() {
    for (double x = 0.0; x <= 1.0; x += 0.1) {

        double y = getA(x);
        printf("x = %.1f\t y = %.6lf\n", x, y);
    }

    return 0;
}

double getA(const double x)
{
    if (1 - x < 0) {
        printf("invalid result ");
        return 0; 
    }
    else {
        double y = sqrt(1 - x) - cos(sqrt(1 - x));
        return y;
    }
}
