#include <stdio.h>

static int answer[] = {-1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 16, 0, 18};

int main() {
    int n;
    scanf("%d", &n);
    int andans = -1, orans = 0, xorans = 0;

    while (n--) {
        int index;
        scanf("%d", &index);

        andans &= answer[index];
        orans |= answer[index];
        xorans ^= answer[index];
    }

    printf("%d %d %d", andans, orans, xorans);
}