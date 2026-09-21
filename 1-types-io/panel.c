#include <stdio.h>

int main() {
    int w = 0;
    char id[55] = {0}, name[55] = {0}, email[55] = {0};
    scanf("%d %[^,],%[^,],%[^\n]", &w, id, name, email);

    printf("| ID       | %-*.*s |\n", w, w, id);
    printf("| Username | %-*.*s |\n", w, w, name);
    printf("| Email    | %-*.*s |", w, w, email);
}