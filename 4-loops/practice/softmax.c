#include <stdio.h>
#include <math.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    double x[105] = {0};
    for (int i = 0; i < n; ++i)
        scanf("%lf", &x[i]);

    for (int i = 0; i < k; ++i) {
        double t, deno = 0.0, var = 0.0;
        scanf("%lf", &t);

        for (int i = 0; i < n; ++i)
            deno += exp(x[i] / t);

        for (int i = 0; i < n; ++i) {
            double temp = exp(x[i] / t) / deno;
            printf("%.3f ", temp);

            var += pow(temp - 1.0/n, 2);
        }
        printf("%.3f\n", var / n);
    }
}