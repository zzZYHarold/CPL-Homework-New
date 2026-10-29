#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int len, n;
    char input[35] = {0};
    scanf("%d %d", &len, &n);
    scanf("%s", input);

    int length = strlen(input);
    int output = 0;
    for (int i = 0; i < length; ++i) {
        char c = input[i];
        int num = 0;
        if (isdigit(c))
            num = c - '0';
        else if (isalpha(c))
            num = c - 'A' + 10;


        if (num >= n) {
            printf("Error");
            return 0;
        }

        output = output * n + num;
    }

    printf("%d", output);
    return 0;
}