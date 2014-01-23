#define file "stars"
#include <cstdio>

const int N = 130;
int t[N][N][N], n;

void inc(int x, int y, int z, int X) {
    for (; x < n; x |= x + 1)
        for (int i = y; i < n; i |= i + 1)
            for (int j = z; j < n; j |= j + 1)
                t[x][i][j] += X;
}

int sum(int x, int y, int z) {
    int r = 0;
    for (; x >= 0; x &= x + 1, x--)
        for (int i = y; i >= 0; i &= i + 1, i--)
            for (int j = z; j >= 0; j &= j + 1, j--)
                r += t[x][i][j];
    return r;
}

int sum(int x1, int y1, int z1, int x2, int y2, int z2) {
    x1--; y1--; z1--;
    return sum(x2,y2,z2)
        -  sum(x2,y2,z1) -  sum(x2,y1,z2) -  sum(x1,y2,z2)
        +  sum(x1,y1,z2) +  sum(x1,y2,z1) +  sum(x2,y1,z1)
        -  sum(x1,y1,z1);
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d", &n);
    for (int k, x, y, z, x1, y1, z1, c; ; ) {
        scanf("%d", &c);
        if (c == 3)
            break;
        if (c == 1) {
            scanf("%d%d%d%d", &x, &y, &z, &k);
            inc(x, y, z, k);
        }
        else {
            scanf("%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1);
            printf("%d\n", sum(x,y,z,x1,y1,z1));
        }
    }

    return 0;
}
