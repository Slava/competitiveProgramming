#define file "dominoes"
#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

long long a[52][1 << 7];
int n, m, x, msk;

void go(int y, int pre, int cur) {
    if (y >= m) {
        if (pre == (1 << m) - 1) {
            a[x + 1][cur] += a[x][msk];
//            printf("%d -> %d\n", msk, cur);
        }
        return;
    }
    if (((pre >> y) & 1) == 1) {
        go(y + 1, pre, cur);
        return ;
    }
    go(y + 1, pre | (1 << y), cur | (1 << y));
    if (((pre >> (y + 1)) & 1) == 0)
        go(y + 2, pre | (1 << y) | (1 << (y + 1)), cur);
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    cin >> n >> m;
    if (n < m)
        swap(n, m);
    a[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 1 << m; j++) {
            if (!a[i][j])continue;
            x = i; msk = j;
            go(0, j, 0);
  //          printf("\n\n");
        }
    cout << a[n][0];
    return 0;
}
