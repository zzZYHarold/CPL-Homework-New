#include <stdio.h>

int main() {
    char op[15] = {0};
    int n;
    scanf("%s %d", op, &n);

    int cube[10][105][105] = {0};
    for (int t = 0; t < 6; ++t)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &cube[t][i][j]);

    if (op[0] == 'r') {
        // rotate n
        int side = 0;
        scanf("%d", &side);

        for (int t = 0; t < 6; ++t) {
            if (t != side) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        printf("%d", cube[t][i][j]);
                        if (j != n - 1)
                            printf(" ");
                    }
                    printf("\n");
                }
            }
            else {
                int temp[105][105];
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        temp[i][j] = cube[side][n - 1 - j][i];

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        printf("%d", temp[i][j]);
                        if (j != n - 1)
                            printf(" ");
                    }
                    printf("\n");
                }
            }
        }

        return 0;
    }

    int index[4][2] = {0};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 2; ++j)
            scanf("%d", &index[i][j]);

    int temp[4][105];
    for (int k = 0; k < 4; ++k) {
        int side = index[k][0], line = index[k][1];

        for (int j = 0; j < n; ++j)
            temp[k][j] = cube[side][line][j];
    }

    // 循环置换
    for (int k = 0; k < 4; ++k) {
        int side = index[k][0], line = index[k][1];
        int prev = (k + 3) % 4;

        for (int j = 0; j < n; ++j)
            cube[side][line][j] = temp[prev][j];
    }

    for (int t = 0; t < 6; ++t) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d", cube[t][i][j]);
                if (j != n - 1)
                    printf(" ");
            }

            printf("\n");
        }
    }
}