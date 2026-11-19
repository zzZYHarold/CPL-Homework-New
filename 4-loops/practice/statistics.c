#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    char input[1005] = {0};
    scanf("%d %s", &n, input);

    int upper[26] ={0}, lower[26] = {0};
    for (int i = 0; i < n; ++i) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z')
            upper[c - 'A']++;
        else
            lower[c - 'a']++;
    }

    int height = 0;
    for (int i = 0; i < 26; ++i) {
        if (upper[i] > height)
            height = upper[i];
        if (lower[i] > height)
            height = lower[i];
    }

    // -----------
    // 上边=的输出
    for (int i = height; i >= 1; --i) {
        bool interval = false;
        for (int j = 0; j < 26; ++j) {
            if (upper[j] == 0 && lower[j] == 0)
                continue;

            // 除队首字母组之间加空格
            if (interval)
                printf(" ");
            interval = true;

            if (lower[j] > 0) {
                if (lower[j] >= i)
                    printf("=");
                else
                    printf(" ");
            }

            if (upper[j] > 0) {
                if (upper[j] >= i)
                    printf("=");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    // -----------
    // 底部----的输出
    int width = 0, group = 0;

    for (int i = 0; i < 26; ++i) {
        if (lower[i] == 0 && upper[i] == 0)
            continue;

        group++;
        if (lower[i] > 0)
            width++;
        if (upper[i] > 0)
            width++;
    }
    width += group - 1;

    for (int i = 0; i < width; ++i)
        printf("-");
    printf("\n");

    // ----------
    // 最底部字母的输出
    bool interval = false;

    for (int i = 0; i < 26; ++i) {
        if (lower[i] == 0 && upper[i] == 0)
            continue;

        if (interval)
            printf(" ");
        interval = true;

        if (lower[i] > 0)
            printf("%c", 'a' + i);
        if (upper[i] > 0)
            printf("%c", 'A' + i);
    }
}