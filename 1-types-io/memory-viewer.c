#include <stdio.h>

int main() {
    unsigned int addr, data;
    scanf("%u %u", &addr, &data);
    printf("0x%08x:  ", addr);

    unsigned int bt1 = (data >> 24) & 0xFF;
    unsigned int bt2 = (data >> 16) & 0xFF;
    unsigned int bt3 = (data >> 8) & 0xFF;
    unsigned int bt4 = data & 0xFF;
    printf("%02x %02x %02x %02x", bt1, bt2, bt3, bt4);
}