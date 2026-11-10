#include <stdio.h>
#include <stdbool.h>

int splitMax(int n) {
    int res = -1;
    while(n) {
        res = res > (n % 10) ? res : (n % 10);
        n /= 10;
    }

    return res;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int reverse(int n) {
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }

    return res;
}

int trans(int n, int radix) {
    int num = reverse(n);

    int res = 0;
    while (num) {
        res = res * radix + num % 10;
        num /= 10;
    }

    return res;
}

int main() {
    int a, b, res;
    scanf("%d %d %d", &a, &b, &res);

    int maxNum = max(max(splitMax(a), splitMax(b)), splitMax(res));
    for (int radix = 2; radix <= 40; ++radix) {
        if (maxNum >= radix)
            continue;

        if (trans(a, radix) * trans(b, radix) == trans(res, radix)) {
            printf("%d", radix);
            return 0;
        }
    }

    printf("0");
    return 0;
}