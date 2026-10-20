#include <stdio.h>

int main() {
    double x;
    int n;
    scanf("%lf %d", &x, &n);

    double term = x, sum = x;
    for (int i = 1; i <= n; ++i) {
        term *= (-1) * x * x * (2 * i - 1) / (2 * i + 1);
        sum += term;
    }

    printf("%.10f", 4 * sum);
}