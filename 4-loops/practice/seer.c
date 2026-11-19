#include <stdio.h>

typedef struct Spirit {
    double x;
    double y;
} SP;

int main() {
    int T = 2000;
    const double alpha = 0.01;
    double w = 1.0, b = 1.0;

    int m;
    scanf("%d", &m);

    SP sp[105] = {0};
    for (int i = 0; i < m; ++i)
        scanf("%lf %lf", &sp[i].x, &sp[i].y);

    while (T--) {
        double bloss = 0.0, wloss = 0.0;
        for (int i = 0; i < m; ++i) {
            bloss += (b + w * sp[i].x) - sp[i].y;
            wloss += ((b + w * sp[i].x) - sp[i].y) * sp[i].x;
        }

        bloss /= m, wloss /= m;
        b -= alpha * bloss;
        w -= alpha * wloss;
    }

    printf("y = %.3f + %.3fx", b, w);
    return 0;
}