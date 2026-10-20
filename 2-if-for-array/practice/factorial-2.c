#include <stdio.h>

#define number 1000000007

int main() {
    int n;
    scanf("%d", &n);

    long long int sum = 0;
    long long int total = 1;
    for (int i = 1; i <= n; ++i) {
        total = (total % number) * i;
        total %= number;

        sum = (sum % number) + total;
        sum %= number;
    }

    printf("%lld", sum);
    return 0;
}