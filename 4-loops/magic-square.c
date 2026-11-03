#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int output[1005][1005] = {0};

    int row = 0, col = n / 2;
    output[row][col] = 1;

    int range = n * n;
    for (int i = 2; i <= range; ++i) {
        int newrow = (row - 1 + n) % n;
        int newcol = (col + 1) % n;

        if (output[newrow][newcol] != 0) {
            newrow = (row + 1) % n;
            newcol = col;
        }
        output[newrow][newcol] = i;
        row = newrow, col = newcol;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", output[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
}