#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, maxnum, t = 0;
    scanf("%d", &n);
    maxnum = n;

    while (n != 1) {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;

        maxnum = max(maxnum, n);
        t++;
    }

    printf("%d %d", t, maxnum);
    return 0;
}