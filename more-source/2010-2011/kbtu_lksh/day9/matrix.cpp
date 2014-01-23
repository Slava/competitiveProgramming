#include <cstdio>
#include <cstring>

const int M = 600;
int n, S, T, N, g[M][M], cost[M][M], f[M][M];
int phi[M], d[M], from[M], u[M], ans, a[M][M];

bool dijkstra() {
    memset(from, ~0, sizeof from);
    memset(u, 0, sizeof u);
    for (int i = 0; i < N; i++)
        d[i] = (1 << 30);
    d[S] = 0;
    for (int k = 0; k < N; k++) {
        int v = -1;
        for (int i = 0; i < N; i++)
            if (!u[i] && (v == -1 || d[v] >  d[i]))
                v = i;
        u[v] = 1;
        for (int i = 0; i < N; i++) {
            if (g[v][i] - f[v][i] <= 0)continue;
            if (d[i] > d[v] - phi[i] + phi[v] + cost[v][i]) {
                d[i] = d[v] - phi[i] + phi[v] + cost[v][i];
                from[i] = v;
            }
        }
    }
    for (int i = 0; i < N; i++)
        phi[i] += d[i];
    return from[T] != -1;
}

int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = n; j < n + n; j++) {
            int x; scanf("%d", &x);
            cost[i][j] = x;
            cost[j][i] = -x;
            g[i][j] = 1;
        }
    S = n + n; T = S + 1; N = T + 1;
    for (int i = 0; i < n; i++) {
        g[S][i] = 1;
        g[i + n][T] = 1;
    }
    while (dijkstra()) {
//        printf("done\n");
        int v = T, u;
        while (v != S) {
            u = from[v];
            f[u][v]++;
            f[v][u]--;
            ans += cost[u][v];
            v = u;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
        for (int j = n; j < n + n; j++)
            if (f[i][j])
                printf("%d %d\n", i + 1, j - n + 1);
    return 0;
}

