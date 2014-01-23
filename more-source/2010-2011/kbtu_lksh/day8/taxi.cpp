#define file "taxi"
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int abs(int x) {
    if (x < 0)
        return  -x;
    return x;
}
int min(int a, int b) {
    return a < b ? a : b;
}
const int N = 510;
int n, to[N], u[N], a[N][N], g[N][N];
int t[N], x[N], y[N], dx[N], dy[N];

int go(int x, int y, int dx, int dy) {
    return abs(x - dx) + abs(y - dy);
}

int go (int i) {
    return go(x[i], y[i], dx[i], dy[i]);
}

bool dfs(int v) {
    if (u[v])
        return false;
    u[v] = true;
    for (int i = 1; i <= n; i++)
        if (a[v][i])
            if (to[i] == 0 || dfs(to[i])) {
                to[i] = v;
                return true;
            }
    return false;
}

void color (int v) {
    u[v] = 1;
    for (int i = 1; i <= n; i++)
        if (g[v][i] && !u[i])
            color(i);
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
//fgsdf
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int h, m;
        scanf("%d:%d", &h, &m);
        t[i] = h * 60 + m;
        scanf("%d %d %d %d", x + i, y + i, dx + i, dy + i);
        for (int j = 1; j < i; j++)
            if (t[j] + go(j) + go(dx[j], dy[j], x[i], y[i]) < t[i])
                a[j][i] = a[i][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        memset(u, 0, sizeof u);
        dfs(i);
    }
    int ans = 0;
    memset(u, 0, sizeof u);
    for (int i = 1; i <= n; i++)
        if (to[i])
            g[i][to[i]] = g[to[i]][i] = 1;
    for (int i = 1; i <= n; i++)
        if (!u[i]) {
            ans++;
            color(i);
        }
    printf("%d\n", ans);
    return 0;
}

