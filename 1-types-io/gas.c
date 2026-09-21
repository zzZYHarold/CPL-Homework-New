#include <stdio.h>

#define R 8.314

int main() {
    double p, l, t;
    scanf("%lf %lf %lf", &p, &l, &t);

    double n = p * l*l*l / R / t;
    printf("%.4e", n);
}
