#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int tempres = 1;
        for (int j = 1; j <= i; ++j) {
            int temp = j % 10007;
            tempres = (tempres * temp) % 10007;
        }
        tempres %= 10007;
        res = (res + tempres) % 10007;
    }
    printf("%d", res);
    return 0;
}