#include <stdio.h>

int main() {
    int n;
    char input[100005] = {0};
    scanf("%d %s", &n, input);

    int count = 0;
    for (int i = 0; i < n / 2; ++i) {
        char front = input[i], rear = input[n - 1 - i];
        if (front != '?') {
            printf("%c", front);
            input[n - 1 - i] = front;
        }
        else if (rear != '?') {
            printf("%c", rear);
        }
        else {
            printf("%0.2d", count);
            count++;
            input[n - 1 - i] = '/';
        }
    }

    count -= 1;
    for (int i = n / 2; i < n; ++i) {
        char c = input[i];
        if (c != '/') {
            printf("%c", c);
        }
        else {
            int ones = count % 10, tens = count / 10;
            int num = ones * 10 + tens;
            printf("%0.2d", num);
            count--;
        }
    }
}