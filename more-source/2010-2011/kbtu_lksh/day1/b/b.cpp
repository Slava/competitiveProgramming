#define file "heaps"
#include <cstdio>
#include <iostream>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

int n, m, a[2][20], N[2];
bool d[1001][1001][2], was[1001][1001][2];

bool doit (int n, int m, int p) {
    if (was[n][m][p])
        return d[n][m][p];
    bool &res = d[n][m][p];
    res = 0;
    was[n][m][p] = 1;
    for (int i = 0; i < N[p] && !res; i++) {
        if (n - a[p][i] >= 0) {
            if (doit(n - a[p][i], m, p ^ 1) == 0)
                res = 1;
        }
        if (m - a[p][i] >= 0) {
            if (doit(n, m - a[p][i], p ^ 1) == 0)
                res = 1;
        }
    }
    return res;
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int j = 0; j < 2; j++) {
        scanf("%d", &N[j]);
        for (int i = 0; i < N[j]; i++)
            scanf("%d", &a[j][i]);
    }
    printf("%s\n", doit(n,m,0) ? "First" : "Second");
    return 0;
}
