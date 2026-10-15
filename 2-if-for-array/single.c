#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int input[1000005] = {0};
    for (int i = 0; i < 2 * n - 1; ++i) {
        int num = 0;
        scanf("%d", &num);
        input[num]++;
    }

    for (int i = 0; i < 1000005; ++i) {
        if (input[i] == 1) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}