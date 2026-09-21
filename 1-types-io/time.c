#include <stdio.h>

int main() {
    char month[10] = {0}, weekday[10] = {0};
    int day, year, hour, min, sec;
    scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour, &min, &sec);

    printf("%.3s %.3s %02d %02d:%02d:%02d %04d", weekday, month, day, hour, min, sec, year);
}