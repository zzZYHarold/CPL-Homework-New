#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char input[1005] = {0};
    scanf("%d %s", &n, input);
    int len = strlen(input);

    char map[1010];
    memset(map, '.', sizeof(map));
    strncpy(&map[3], input, len);
    // for (int i = 3; i < len + 3; ++i)
    //     map[i] = input[i - 3];

    while(n--) {
        char newmap[1010];
        memset(newmap, '.', sizeof(newmap));
        memcpy(newmap, map, sizeof(map));

        for (int i = 3; i < len + 3; ++i) {
            char c = map[i];

            int Acount = 0, Bcount = 0;
            for (int k = i - 3; k <= i + 3; ++k) {
                if (k == i)
                    continue;

                if (map[k] == 'A')
                    Acount++;
                else if (map[k] == 'B')
                    Bcount++;
            }

            if (c == '.') {
                if (Acount >= 2 && Acount <= 4 && Bcount == 0)
                    newmap[i] = 'A';
                else if (Bcount >= 2 && Bcount <= 4 && Acount == 0)
                    newmap[i] = 'B';
            }

            else if (c == 'A') {
                if (Bcount > 0 || Acount >= 5 || Acount <= 1)
                    newmap[i] = '.';
            }

            else {
                if (Acount > 0 || Bcount >= 5 || Bcount <= 1)
                    newmap[i] = '.';
            }
        }

        memcpy(map, newmap, sizeof(map));
    }

    map[len + 3] = '\0';
    printf("%s", &map[3]);
}