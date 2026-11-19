#include <stdio.h>

int q[2005][2005];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char input[2005] = {0};
    scanf("%s", input);

    for (int j = 1; j <= n; ++j)
        q[0][j] = input[j - 1] - '0';
    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (q[i - 1][j] == 1) {
                int num = !(q[i - 1][j - 1] & q[i - 1][j + 1]);
                q[i][j] = num;
            }
            else {
                q[i][j] = q[i - 1][j + 1];
            }
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j <= n; ++j)
            printf("%d", q[i][j]);
        printf("\n");
    }

    return 0;
}