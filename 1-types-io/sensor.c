#include <ctype.h>
#include <stdio.h>

int main() {
    char name[21] = {0}, unit;
    int pre = 0;
    double frac = 0.0, factor = 0.0;

    scanf("%s %d %lf %lf %c", name, &pre, &frac, &factor, &unit);
    printf("%.2s: %d (%.5lf) | %.5E %.5lf %c", name, pre, frac, pre+frac, (pre+frac)*factor, toupper(unit));
}