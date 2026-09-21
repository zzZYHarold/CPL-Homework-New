#include <stdio.h>
#include <math.h>

int main() {
    int xa, ya, xb, yb;
    double distance, azimuth;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);

    int deltax = xb - xa, deltay = yb - ya;
    distance = hypot(deltax, deltay);

    double rad = atan2(deltay, deltax);
    double degree = rad * 180 / acos(-1);

    double res = 90 - degree;
    res = fmod(res + 360, 360);

    printf("%.4lf %.4lf", distance, res);
}