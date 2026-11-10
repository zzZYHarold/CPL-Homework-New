#include <stdio.h>

static char *ones[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty",
  "fifty", "sixty", "seventy", "eighty", "ninety"};

int check(int num) {
    int digit = 0;
    while (num) {
        digit++;
        num /= 10;
    }
    return digit;
}

void printNum(int num) {
    int digit = check(num);
    switch(digit) {
        case 3:
            int temp3 = num / 100;
            printf("%s hundred ", ones[temp3]);

            num -= temp3 * 100;
            if (num == 0)
                return;
            printf("and ");

        case 2:
            int temp2 = num / 10;
            if (temp2 == 1) {
                printf("%s ", ones[num]);
                return;
            }

            int temp21 = num % 10;
            if (temp2 != 0){
                if (temp21 == 0) {
                    printf("%s ", tens[temp2]);
                }
                else {
                    printf("%s-%s ", tens[temp2], ones[temp21]);
                }
            }
            else {
                if (temp21 == 0) {
                    return;
                }
                else {
                    printf("%s ", ones[temp21]);
                }
            }
            break;

        case 1:
            printf("%s ", ones[num]);
            break;
    }
}

int main() {
    int num;
    scanf("%d", &num);

    if (num == 0) {
        printf("zero");
        return 0;
    }
    if (num == -2147483648) {
        printf("minus two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-eight");
        return 0;
    }

    if (num < 0) {
        printf("minus ");
        num = -num;
    }

    int digit = check(num);
    if (digit == 10) {
        int a = num / 1000000000;
        printf("%s billion ", ones[a]);

        num -= a * 1000000000;
        if (num == 0)
            return 0;
        digit = 9;
    }

    switch((digit + 2) / 3) {
        case 3:
            int temp3 = num / 1000000;
            if (temp3 != 0) {
                printNum(temp3);
                printf("million ");
                num -= temp3 * 1000000;
            }

        case 2:
            int temp2 = num / 1000;
            if (temp2 != 0) {
                printNum(temp2);
                printf("thousand ");
                num -= temp2 * 1000;
            }

        case 1:
            if (num != 0) {
                printNum(num);
            }
            break;
    }

    return 0;
}