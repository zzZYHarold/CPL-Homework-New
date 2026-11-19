#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa, ya, xb, yb, xc, yc;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);

    int xdelta = abs(xa - xb), ydelta = abs(ya - yb);
    int len = xdelta + ydelta;

    // 1. 直线
    if (xa == xb) {
        int low = ya < yb ? ya : yb, high = ya > yb ? ya : yb;

        if (xc == xa && low < yc && yc < high) {
            len += 2;
            printf("%d\nR", len);
        }
        else {
            printf("%d\n", len);
        }

        for (int i = 0; i < ydelta; ++i)
            printf("%c", ya > yb ? 'D' : 'U');

        if (xc == xa && low < yc && yc < high)
            printf("L");

        return 0;
    }

    if (ya == yb) {
        int low = xa < xb ? xa : xb, high = xa > xb ? xa : xb;

        if (yc == ya && low < xc && xc < high) {
            len += 2;
            printf("%d\nU", len);
        }
        else {
            printf("%d\n", len);
        }

        for (int i = 0; i < xdelta; ++i)
            printf("%c", xa > xb ? 'L' : 'R');

        if (yc == ya && low < xc && xc < high)
            printf("D");

        return 0;
    }

    // 2. 折线
    printf("%d\n", len);
    if (xc == xb || yc == ya) {
        // 先执行竖向移动
        for (int i = 0; i < ydelta; ++i)
            printf("%c", ya > yb ? 'D' : 'U');

        for (int i = 0; i < xdelta; ++i)
            printf("%c", xa > xb ? 'L' : 'R');

        return 0;
    }

    // 先执行横向移动
    for (int i = 0; i < xdelta; ++i)
        printf("%c", xa > xb ? 'L' : 'R');

    for (int i = 0; i < ydelta; ++i)
        printf("%c", ya > yb ? 'D' : 'U');

    return 0;
}