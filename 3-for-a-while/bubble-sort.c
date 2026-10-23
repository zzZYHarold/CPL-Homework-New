#include <stdio.h>
#include <limits.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int total;
        scanf("%d", &total);

        int maxnum = INT_MIN;
        int num;
        while (total--) {
            scanf("%d", &num);
            maxnum = max(maxnum, num);
        }

        if (maxnum == num)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}