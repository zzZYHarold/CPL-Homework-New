#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char str[2005] = {0};
    scanf("%s", str);

    for (int i = 0; i < n; ++i) {
        char c = str[i], cr = str[n - 1 - i];
        if (c != '?')
            printf("%c", c);
        else
            printf("%c", cr);
    }

    return 0;
}