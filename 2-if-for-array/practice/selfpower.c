#include <stdio.h>
#include <math.h>

int main() {
    int n, m = 0;
    scanf("%d", &n);
    int temp = n;

    while (temp) {
        m++;
        temp /= 10;
    }
    int mtemp = m;
    temp = n;

    double sum = 0.0;
    while (mtemp) {
        int digit = temp % 10;
        sum += pow(digit, m);
        mtemp--;
        temp /= 10;
    }

    if (sum == (double)n)
        printf("%d", m);
    else
        printf("0");

    return 0;
}