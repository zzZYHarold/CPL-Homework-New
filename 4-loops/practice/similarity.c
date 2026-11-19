#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int input[105][105] = {0};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m;++j)
            scanf("%d", &input[i][j]);

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m;++j) {
            int num;
            scanf("%d", &num);

            if (num == input[i][j])
                count++;
        }
    }

    double res = count / 1.0 / n / m;
    printf("%.2f", res * 100);
}