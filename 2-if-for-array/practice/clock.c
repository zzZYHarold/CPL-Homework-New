#include <stdio.h>

int main() {
    int hour, min;
    scanf("%d:%d", &hour, &min);

    if (hour / 13 == 0) {
        if (hour / 12 == 0)
            printf("%02d:%02d a.m.", hour, min);
        else
            printf("%02d:%02d p.m.", hour, min);

        return 0;
    }

    hour -= 12;
    printf("%02d:%02d p.m.", hour, min);
    return 0;
}