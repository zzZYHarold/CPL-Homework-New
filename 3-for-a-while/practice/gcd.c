#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int temp = 0;
    while (b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }

    printf("%d", a);
    return 0;
}