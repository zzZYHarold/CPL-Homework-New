#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) {
        printf("equilateral triangle");
        return 0;
    }

    int temp1 = min(a, b), temp2 = max(a, b);
    int minl = min(temp1, c), maxl = max(temp2, c);
    int med = a + b + c - minl - maxl;

    if (minl + med <= maxl) {
        printf("not triangle");
        return 0;
    }

    int mins = minl * minl, meds = med * med, maxs = maxl * maxl;

    if (mins + meds == maxs) {
        printf("right triangle");
        return 0;
    }

    if (mins + meds > maxs)
        printf("acute ");
    else
        printf("obtuse ");

    if (minl == med || med == maxl || minl == maxl)
        printf("isosceles ");

    printf("triangle");
    return 0;
}