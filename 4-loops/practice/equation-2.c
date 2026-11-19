#include <stdio.h>

int main() {
    double mtx[3][4];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            scanf("%lf", &mtx[i][j]);

    double a1 = mtx[0][0], b1 = mtx[0][1], c1 = mtx[0][2], d1 = mtx[0][3];
    double a2 = mtx[1][0], b2 = mtx[1][1], c2 = mtx[1][2], d2 = mtx[1][3];
    double a3 = mtx[2][0], b3 = mtx[2][1], c3 = mtx[2][2], d3 = mtx[2][3];

    double delta = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
    double deltax = d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);
    double deltay = a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);
    double deltaz = a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);

    double x = deltax / delta, y = deltay / delta, z = deltaz / delta;
    printf("%.2f %.2f %.2f", x, y, z);
}