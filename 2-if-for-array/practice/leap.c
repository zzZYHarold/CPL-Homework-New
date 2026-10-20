#include <stdio.h>

void isLeap(unsigned long long int n) {
    if (n % 4 != 0)
        printf("Normal year!");
    else if (n % 100 != 0)
        printf("Leap year!");
    else if (n % 400 != 0)
        printf("Normal year!");
    else
        printf("Leap year!");
}

int main() {
    unsigned long long int n, k;
    scanf("%llu %llu", &n, &k);

    isLeap(n);
    printf("\n");
    isLeap(n + k);

    return 0;
}