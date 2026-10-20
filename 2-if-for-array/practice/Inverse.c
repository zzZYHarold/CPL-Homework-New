#include <stdio.h>

int main() {
    int n, k;
    char str[10000005] = {0}, front[10000005] = {0}, rear[10000005] = {0};
    scanf("%d", &n);
    getchar();
    fgets(str, n + 1, stdin);
    scanf("%d", &k);

    for (int i = k - 1; i >= 0; --i) {
        char c = str[i];
        front[k - 1 - i] = c;
    }
    front[k] = '\0';

    for (int i = n - 1; i >= k; --i) {
        char c = str[i];
        rear[n - 1 - i] = c;
    }
    rear[n - k] = '\0';

    printf("%s%s", front, rear);
    return 0;
}