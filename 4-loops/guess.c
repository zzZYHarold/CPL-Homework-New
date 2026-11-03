#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    unsigned int upper = UINT_MAX, lower = 0;
    unsigned int guess = lower + (upper - lower) / 2;

    char res[5] = {0};
    while(1) {
        printf("%u\n", guess);
        fflush(stdout);
        scanf("%s", res);

        switch(res[0]) {
            case 'G':
                upper = guess - 1;
                guess = lower + (upper - lower) / 2;
                break;

            case 'L':
                lower = guess + 1;
                guess = lower + (upper - lower) / 2;
                break;

            case 'E':
            case 'O':
                return 0;
        }
    }
}