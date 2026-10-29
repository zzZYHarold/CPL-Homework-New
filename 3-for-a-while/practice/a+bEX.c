#include <stdio.h>
#include <string.h>

int main() {
    char a[1005] = {0}, b[1005] = {0};
    while (scanf("%s %s", a, b) != EOF) {
        int alen = strlen(a), blen = strlen(b);
        int anum[1005] = {0}, bnum[1005] = {0}, result[1005] = {0};

        for (int i = 0; i < alen; ++i)
            anum[i] = a[alen - 1 - i] - '0';
        for (int i = 0; i < blen; ++i)
            bnum[i] = b[blen - 1 - i] - '0';

        int shortLen = alen < blen ? alen : blen;
        int i = 0;
        for (; i < shortLen; ++i) {
            int sum = result[i] + anum[i] + bnum[i];
            if (sum >= 10)
                result[i + 1] = 1;

            result[i] = sum % 10;
        }

        while (i < alen) {
            int sum = result[i] + anum[i];
            if (sum >= 10)
                result[i + 1] = 1;
            result[i] = sum % 10;
            i++;
        }
        while (i < blen) {
            int sum = result[i] + bnum[i];
            if (sum >= 10)
                result[i + 1] = 1;
            result[i] = sum % 10;
            i++;
        }

        if (result[i] == 1)
            printf("1");
        i -= 1;
        for (; i >= 0; --i)
            printf("%d", result[i]);
        printf("\n");
    }
}