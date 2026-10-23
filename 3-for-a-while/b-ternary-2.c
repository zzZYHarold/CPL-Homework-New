#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char input[20] = {0};
        scanf("%s", input);
        int len = strlen(input);
        int temp = 0;
        bool isValid = true, isNegative = false;

        int i;
        // 处理0和负号
        char first = input[0];
        if (first == '0') {
            printf("0\n");
            continue;
        }
        if (first == '-') {
            i = 1;
            isNegative = true;
        }
        else
            i = 0;

        for (; i < len; ++i) {
            char c = input[i];
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
            temp = temp * 10 + (c - '0');
        }

        // 不合法输入在这里结束
        if (!isValid) {
            printf("Radix Error\n");
            continue;
        }

        // 十进制temp转三进制，结果是逆序存储的
        char reverseNum[100] = {0};
        int p = 0;
        while (temp) {
            int digit = temp % 3;
            reverseNum[p++] = digit + '0';
            temp /= 3;
        }

        // 转换为平衡三进制
        char output[105] = {0};
        int rNumlen = strlen(reverseNum);
        int outputP = 0;
        bool carryFlag = false;
        for (int j = 0; j < rNumlen; ++j) {
            char c = reverseNum[j];
            if (carryFlag)
                c++;

            if (c == '0' || c == '1') {
                output[outputP++] = c;
                if (isNegative && c == '1')
                    output[outputP - 1] = 'Z';
                carryFlag = false;
            }
            else if (c == '2') {
                if (isNegative)
                    output[outputP++] = '1';
                else
                    output[outputP++] = 'Z';
                carryFlag = true;
            }
            else if (c == '3') {
                output[outputP++] = '0';
                carryFlag = true;
            }
        }
        if (carryFlag) {
            if (isNegative)
                output[outputP] = 'Z';
            else
                output[outputP] = '1';
        }

        int outputLen = strlen(output);
        for (int j = outputLen - 1; j >= 0; --j)
            printf("%c", output[j]);
        printf("\n");
    }

    return 0;
}