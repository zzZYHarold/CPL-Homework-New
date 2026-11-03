#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n%d\n%d\n%d\n", a & b, a | b, a ^ b, ~a);
    printf("%d\n%d\n%d\n", a << b, a >> b, (a >> b) & 1);

    int count = 0;
    while (a) {
        count += a & 1;
        a >>= 1;
    }
    printf("%d", count);

    return 0;
}