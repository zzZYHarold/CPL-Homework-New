#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int reverse(int n) {
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }

    return res;
}

bool isPrime(int n) {
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0)
        return false;

    int range = sqrt(n);
    for (int i = 3; i <= range; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (isPrime(i)) {
            int num = reverse(i);
            if (isPrime(num))
                count++;
        }
    }

    printf("%d", count);
    return 0;
}