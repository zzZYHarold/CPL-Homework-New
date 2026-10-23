#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i * i <= n; ++i)
        printf("%d ", i * i);

    return 0;
}

// #include <stdbool.h>
//
// int main() {
//     int n;
//     scanf("%d", &n);
//
//     bool str[2005] = {false};
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j * i <= n; ++j) {
//             int index = j * i;
//             if (str[index] == false)
//                 str[index] = true;
//             else
//                 str[index] = false;
//         }
//     }
//
//     for (int i = 1; i <= n; ++i) {
//         if (str[i] == true)
//             printf("%d ", i);
//     }
//
//     return 0;
// }