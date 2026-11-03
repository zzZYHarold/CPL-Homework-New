#include <stdio.h>

int vectors[8][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
};

int main() {
    char map[105][105] = {0};
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%c", &map[i][j]);
        getchar();
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c = map[i][j];
            if (c == '*') {
                printf("*");
                continue;
            }

            // c == 'o'
            int count = 0;
            for (int k = 0; k < 8; ++k) {
                int newrow = i + vectors[k][0], newcol = j + vectors[k][1];
                if (newrow < 0 || newrow >= n || newcol < 0 || newcol >= n)
                    continue;

                if (map[newrow][newcol] == '*')
                    count++;
            }
            printf("%d", count);
        }

        printf("\n");
    }
}