#include <cstdio>
#include <cstring>

const int M = 550, inf = 1 << 30;
int n, S, T, N, g[M][M], cost[M][M], f[M][M];
int from[M], u[M], a[M][M];
int d[M], phi[M], ans;//, infl = 1LL << 62;

bool dijkstra() {
    memset(from, ~0, sizeof from);
    memset(u, 0, sizeof u);
    int i, k, v;
	for (i = 0; i < N; ++i)
        d[i] = inf;
    d[S] = 0;
    for (k = 0; k < N; ++k) {
        v = -1;
        for (i = 0; i < N; ++i)
            if (!u[i] && (v == -1 || d[v] >  d[i]))
                v = i;
        u[v] = 1;
        for (i = 0; i < N; ++i) {
            if (g[v][i] - f[v][i] <= 0)continue;
            if (d[i] > d[v] - phi[i] + phi[v] + cost[v][i]) {
                d[i] = d[v] - phi[i] + phi[v] + cost[v][i];
                from[i] = v;
            }
        }
    }
    for (i = 0; i < N; i++)
        phi[i] += d[i];
    return from[T] != -1;
}

int main() {
	int i, j, v, x, u;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        for (j = n; j < n + n; ++j) {
            scanf("%d", &x);
			cost[i][j] = x;
            cost[j][i] = -x;
            g[i][j] = 1;
        }
    S = n + n; T = S + 1; N = T + 1;
    for (i = 0; i < n; ++i) {
        g[S][i] = 1;
        g[i + n][T] = 1;
    }
    while (dijkstra()) {
        v = T;
        while (v != S) {
            u = from[v];
            f[u][v]++;
            f[v][u]--;
            ans += cost[u][v];
            v = u;
        }
    }
    printf("%d\n", ans);
    for (i = 0; i < n; i++)
        for (j = n; j < n + n; j++)
            if (f[i][j])
                printf("%d %d\n", i + 1, j - n + 1);
	return 0;
}

