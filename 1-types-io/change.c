#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int fifty = n / 50;
    n %= 50;
    int twenty = n / 20;
    n %= 20;
    int ten = n / 10;
    n %= 10;
    int five = n / 5;
    n %= 5;
    int one = n;

    printf("%d\n%d\n%d\n%d\n%d", fifty, twenty, ten, five, one);
}