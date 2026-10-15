#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0, need = 0;
    for (int i = 0; i < n; ++i) {
        int deg;
        scanf("%d", &deg);
        sum += deg;

        if (sum < i + 1) {
            need += i + 1 - sum;
            sum = i + 1;
        }
    }

    printf("%d", need);
}