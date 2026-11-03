#include <stdio.h>

int main() {
    int num[10][10] = {0};

    for (int i = 0; i < 9; ++i) {
        int sum = 0, mul = 1, ssum = 0;
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &num[i][j]);
            sum += num[i][j];
            mul *= num[i][j];
            ssum += num[i][j] * num[i][j];
        }

        if (sum != 45 || mul != 362880 || ssum != 285) {
            printf("NO");
            return 0;
        }
    }

    for (int i = 0; i < 9; ++i) {
        int sum = 0, mul = 1, ssum = 0;
        for (int j = 0; j < 9; ++j) {
            sum += num[j][i];
            mul *= num[j][i];
            ssum += num[j][i] * num[j][i];
        }

        if (sum != 45 || mul != 362880 || ssum != 285) {
            printf("NO");
            return 0;
        }
    }

    for (int k = 0; k < 9; ++k) {
        int sum = 0, mul = 1, ssum = 0;
        for (int i = 3 * (k / 3); i < 3 * (k / 3) + 3; ++i) {
            for (int j = 3 * (k % 3); j < 3 * (k % 3) + 3; ++j) {
                sum += num[i][j];
                mul *= num[i][j];
                ssum += num[i][j] * num[i][j];
            }
        }

        if (sum != 45 || mul != 362880 || ssum != 285) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}