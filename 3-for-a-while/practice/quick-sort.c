#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int num[1000005] = {0};
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);

    int pivot = num[k - 1];
    int left = 0, right = n - 1;

    while (left < right) {
        while (num[left] < pivot && left < right)
            left++;
        while (num[right] >= pivot && right > left)
            right--;

        if (left != right) {
            int temp = num[left];
            num[left] = num[right];
            num[right] = temp;
        }
    }

    int index = 0;
    for (int i = 0; i < n; ++i)
        if (num[i] == pivot)
            index = i;

    int temp = num[left];
    num[left] = pivot;
    num[index] = temp;


    for (int i = 0; i < n; ++i)
        printf("%d ", num[i]);
}