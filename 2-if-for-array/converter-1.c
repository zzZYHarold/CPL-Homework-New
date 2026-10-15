#include <stdio.h>

static char *ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
    "0", "1", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
    int num, temp;
    scanf("%d", &num);
    temp = num;

    int digit = 0;
    while (temp) {
        digit++;
        temp /= 10;
    }

    if (digit <= 1) {
        printf("%s", ones[num]);
        return 0;
    }

    int tendigit = num / 10 % 10;
    int onedigit = num % 10;
    if (digit == 2) {
        if (tendigit == 1) {
            printf("%s", ones[num]);
            return 0;
        }

        if (onedigit == 0) {
            printf("%s", tens[tendigit]);
            return 0;
        }

        printf("%s-%s", tens[tendigit], ones[onedigit]);
        return 0;
    }

    // digit == 3 100~999
    int hundigit = num / 100;
    printf("%s hundred", ones[hundigit]);
    if (tendigit == 0 && onedigit == 0)
        return 0;

    printf(" and ");
    if (tendigit == 1) {
        printf("%s", ones[num % 100]);
        return 0;
    }

    if (tendigit == 0) {
        printf("%s", ones[onedigit]);
        return 0;
    }

    if (onedigit == 0) {
        printf("%s", tens[tendigit]);
        return 0;
    }

    printf("%s-%s", tens[tendigit], ones[onedigit]);
    return 0;
}