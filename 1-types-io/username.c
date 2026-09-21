#include <stdio.h>
#include <string.h>

int main() {
    char input[105] = {0};
    scanf("%[^\n]", input);

    int length = strlen(input);
    printf("%d\n\"%.20s\"", length, input);
}