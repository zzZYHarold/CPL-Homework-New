#include <stdio.h>
#include <stdbool.h>

int n, m;
char map[55][55];
bool visited[55][55];

static int vector[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool check(int x, int y) {
    if (map[x][y] != '#') // 包含了位置越界情况
        return false;

    if (visited[x][y])
        return false;

    return true;
}

typedef struct Position {
    int x;
    int y;
} Pos;

int main() {
    int x0, y0;
    scanf("%d %d %d %d", &n, &m, &x0, &y0);

    for (int i = 1; i <= n; ++i)
        scanf("%s", &map[i][1]);

    int pathLen = 1;
    int x = x0, y = y0;
    visited[x0][y0] = true;

    Pos pos[3000] = {0};
    pos[0].x = x, pos[0].y = y;

    while (1) {
        bool valid = false;
        int newx = 0, newy = 0;
        for (int i = 0; i < 4; ++i) {
            newx = x + vector[i][0], newy = y + vector[i][1];
            if (check(newx, newy)) {
                valid = true;
                break;
            }
        }

        if (valid) {
            x = newx;
            y = newy;

            visited[x][y] = true;
            pos[pathLen].x = x, pos[pathLen].y = y;
            pathLen++;
        }
        else
            break;
    }

    printf("%d\n", pathLen);
    for (int i = 0; i < pathLen; ++i)
        printf("%d %d\n", pos[i].x, pos[i].y);

    return 0;
}