#define file "flow"
#include <cstdio>
#include <cstring>

int min(int a, int b) {
    return a < b ? a : b;
}
const int N = 510;
int n, m, f[N][N], c[N][N], l[N], q[N + N], h, t, ptr[N];

bool bfs() {
    for (int i = 0; i < n; i++)
        l[i] = 0;
    l[0] = 1;
    h = t = 0;
    q[t++] = 0;
    while(h < t) {
        int v = q[h++];
        for (int i = 0; i < n; i++)
            if (c[v][i] - f[v][i] > 0 && !l[i]) {
                l[i] = l[v] + 1;
                q[t++] = i;
            }
    }
    return l[n - 1] != 0;
}

int dfs(int v, int flow) {
    if (v == n - 1)
        return flow;
    for (int &i = ptr[v]; i < n; i++) {
        if (c[v][i] - f[v][i] <= 0 || l[i] != l[v] + 1)
            continue;
        int push = dfs(i, min(flow, c[v][i] - f[v][i]));
        if (push != 0) {
            f[v][i] += push;
            f[i][v] = -f[v][i];
            return push;
        }
    }
    return 0;
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--; y--;
        c[x][y] = z;
    }
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(dfs(0, (1 << 30)));
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += f[0][i];
    printf("%d\n", ans);

    return 0;
}

