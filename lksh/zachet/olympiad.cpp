#include <cstdio>
#include <cstring>
#define min(a,b) (a<b?a:b)

const int maxn = 250;
int l[maxn], f[maxn][maxn], c[maxn][maxn],
    s, t, n, n1, n2, k, q[maxn], j[maxn];

bool bfs () {
    memset(l, -1, sizeof(l[0]) * n);
    int qh, qt;
    qh = qt = 0;
    q[qt++] = s;
    l[s] = 0;

    while (qh < qt) {
        int v = q[qh++];
        for (int i = 0; i < n; i++)
            if (l[i] == -1 && c[v][i] - f[v][i] > 0) {
                l[i] = l[v] + 1;
                q[qt++] = i;
            }
    }

    return l[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)
        return 0;
    if (v == t)
        return flow;
    for (; j[v] < n; j[v]++)
        if (l[j[v]] == l[v] + 1) {
            int pushed = dfs (j[v], min(flow, c[v][j[v]] - f[v][j[v]]));
            if (pushed) {
                f[v][j[v]] += pushed;
                f[j[v]][v] -= pushed;
                return pushed;
            }
        }
    return 0;
}

int dinic () {
    int flow = 0, pushed;
    while (bfs()) {
        memset (j, 0, sizeof(j[0]) * n);
        while (pushed = dfs(s, 1 << 30))
            flow += pushed;
    }
    return flow;
}

int main () {

    scanf ("%d%d%d", &n1, &n2, &k);
    n = n1 + n2 + 2;
	s = n - 2; t = s + 1;
	for (int i = 0; i < k; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y = y + n1 - 1;
		c[x][y] = 1;
	}
	for (int i = 0; i < n1; i++)
		c[s][i] = 1;
	for (int i = 0; i < n2; i++)
		c[i + n1][t] = 2;

    printf("%d\n", dinic());

    return 0;
}

