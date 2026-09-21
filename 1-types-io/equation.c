#include <stdio.h>
#include <math.h>

int main() {
    int p, q;
    scanf("%d %d", &p, &q);

    long double x;
    long double p1 = p;
    long double q1 = q;
    long double delta = q1*q1/4.0 + p1*p1*p1/27.0;

    x = cbrtl((-q1)/2.0 + sqrtl(delta)) + cbrtl((-q1)/2.0 - sqrtl(delta));
    printf("%.3Lf", x);
    return 0;
}