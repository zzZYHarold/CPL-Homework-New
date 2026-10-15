#include <stdio.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))


int main() {
    int n;
    scanf("%d", &n);

    int res = 0;
    while (n != 495) {
        int ones = n % 10, tens = n / 10 % 10, huns = n / 100;
        int minn = min(min(ones, tens), huns);
        int maxn = max(max(ones, tens), huns);

        int newn = 99 * (maxn - minn);
        if (n > newn)
            res += n - newn;

        n = newn;
    }

    printf("%d", res);
}