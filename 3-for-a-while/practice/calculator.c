#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    char op[5] = {0};

    while (scanf("%d %s %d", &a, op, &b) != EOF) {
        switch(op[0]) {
            case '+':
                printf("%d\n", a + b);
                break;

            case '-':
                printf("%d\n", a - b);
                break;

            case '*':
                if (op[1] == '*') {
                    printf("%.0f\n", pow(a, b));
                    break;
                }
                printf("%d\n", a * b);
                break;

            case '/':
                if (op[1] == '*') {
                    printf("%.3lf\n", (double)a / b);
                    break;
                }
                printf("%d\n", a / b);
                break;

            case '%':
                printf("%d\n", a % b);
                break;
        }
    }
}