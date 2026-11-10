#include <stdio.h>

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    int res = 0, pow = 1;
    for (int i = n; i >= 1; --i) {
        res += t * pow * i;
        pow *= 10;
    }

    printf("%d", res);
    return 0;
}