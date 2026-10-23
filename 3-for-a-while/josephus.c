#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    bool isAlive[505] = {true};
    for (int i = 1; i <= n; ++i)
        isAlive[i] = true;

    int index = 0, count = 0, total = 0;
    while (1) {
        if (total == n - 1)
            break;

        if (isAlive[index]) {
            count++;

            if (count == k) {
                total++;
                isAlive[index] = false;
                count = 0;
            }
        }
        index = (index + 1) % n;
    }

    for (int i = 0; i < n; ++i) {
        if (isAlive[i]) {
            printf("%d", i + 1);
            break;
        }
    }

    return 0;
}