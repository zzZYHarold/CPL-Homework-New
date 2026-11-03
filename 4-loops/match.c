#include <stdio.h>
#include <stdbool.h>

// num, count, row/col
int pos[505 * 505 / 2][2][2];

// count[num] = 0/1/2
int count[505 * 505 / 2];

static int vector[4][2] = {
    {1, 0},
{-1, 0},
{0, 1},
{0, -1}
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int map[505][505] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num = 0;
            scanf("%d", &num);

            map[i][j] = num;
            pos[num][count[num]][0] = i;
            pos[num][count[num]++][1] = j;
        }
    }

    int range = n * m / 2;
    for (int i = 1; i <= range; ++i) {
        int arow = pos[i][0][0], acol = pos[i][0][1];
        int brow = pos[i][1][0], bcol = pos[i][1][1];

        bool valid = false;
        for (int k = 0; k < 4; ++k) {
            int arowNew = arow + vector[k][0], acolNew = acol + vector[k][1];

            while(arowNew >= 0 && arowNew < n &&
            acolNew >= 0 && acolNew < m &&
            map[arowNew][acolNew] == 0) {
                arowNew += vector[k][0];
                acolNew += vector[k][1];
            }

            if (!(arowNew < 0 || arowNew >= n ||
            acolNew < 0 || acolNew >= m)) {
                continue;
            }

            int browNew = brow + vector[k][0], bcolNew = bcol + vector[k][1];

            while(browNew >= 0 && browNew < n &&
            bcolNew >= 0 && bcolNew < m &&
            map[browNew][bcolNew] == 0) {
                browNew += vector[k][0];
                bcolNew += vector[k][1];
            }

            if (!(browNew < 0 || browNew >= n ||
            bcolNew < 0 || bcolNew >= m)) {
                continue;
            }

            valid = true;
            break;
        }

        if (valid) {
            map[arow][acol] = 0, map[brow][bcol] = 0;
            count[i] = 0;
            printf("%d ", i);
        }
    }

}