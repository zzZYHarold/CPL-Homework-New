#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int startSpace = ((n - 2) + 7) % 7;
    int count = 6 - startSpace;
    while (startSpace--)
        printf("    ");

    for (int i = 1; i <= m; ++i) {
        if (i <= 9)
            printf(" %d", i);
        else
            printf("%d", i);

        if (count) {
            printf("  ");
            count--;
        }
        else {
            printf("\n");
            count = 6;
        }
    }
}