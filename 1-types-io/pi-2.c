#include <stdio.h>
#include <math.h>

int main() {
    double pi1 = 0.0, pi2 = 0.0;

    double part = pow(5280, 3) * pow((236674 + 30303 * sqrt(61)), 3) + 744;
    pi1 = log(part) / sqrt(427);
    pi2 = 6 * atan(1.0 / 8) + 2 * atan(1.0 / 57) + atan(1.0 / 239);

    printf("%.15lf\n%.15lf", pi1, 4*pi2);
}