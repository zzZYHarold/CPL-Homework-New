#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int input[2005] = {0};
    for (int i = 0; i < n; ++i)
        scanf("%d", &input[i]);

    int num = input[n - 1], pk = -1;
    int temp[2005] = {0};
    temp[0] = num;
    int j = 1, index = -1;

    for (int i = n - 2; i >= 0; --i) {
        if (input[i] <= num) {
            pk = input[i];
            index = i;
            break;
        }

        num = input[i];
        temp[j++] = num;
    }

    for (int i = 0; i < j; ++i) {
        if (pk < temp[i]) {
            int t = pk;
            pk = temp[i];
            temp[i] = t;
            break;
        }
    }

    for (int i = 0; i < index; ++i)
        printf("%d ", input[i]);
    printf("%d ", pk);
    for (int i = 0; i < j; ++i)
        printf("%d ", temp[i]);

    return 0;
}