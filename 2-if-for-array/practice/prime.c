#include <stdio.h>
#include <stdbool.h>

bool isPrime[50000005];
int primes[50000005];

int main() {
    int n;
    scanf("%d", &n);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i)
        isPrime[i] = 1;

    int total = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i])
            primes[total++] = i;

        for (int j = 0; j < total && i * primes[j] <= n; ++j) {
            int num = i * primes[j];
            isPrime[num] = false;

            if (i % primes[j] == 0)
                break;
        }
    }

    printf("%d", total);
    return 0;
}