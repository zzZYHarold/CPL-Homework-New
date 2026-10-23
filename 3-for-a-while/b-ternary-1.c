#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char input[20] = {0};
        scanf("%s", input);
        int len = strlen(input);
        int output = 0;
        bool isValid = true;

        for (int i = 0; i < len; ++i) {
            char c = input[i];
            if (c == 'Z')
                output += -1 * pow(3, (len - 1 - i));
            else if (c == '1')
                output += 1 * pow(3, (len - 1 - i));
            else if (c == '0')
                continue;
            else {
                isValid = false;
                break;
            }
        }

        if (!isValid)
            printf("Radix Error\n");
        else
            printf("%d\n", output);
    }
}