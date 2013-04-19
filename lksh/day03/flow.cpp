#include <cstdio>
#include <cstdlib>
#include <cstring>
#define min(a,b) (a<b?a:b)

const int N = 510;
int n, m, c[N][N], f[N][N], fr[N], q[N], h, t;

bool bfs(int K) {
	memset(fr, -1, sizeof fr);
	h = t = 0; q[t++] = 0;
	while (h < t) {
		int v = q[h++];
		for (int i = 0; i < n; i++)
			if (c[v][i] - f[v][i] >= K && fr[i] == -1) {
				fr[i] = v; q[t++] = i;
			}
	}
	return fr[n - 1] != -1;
}

int main() {
#ifndef imslavko
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		x--; y--; c[x][y] = z;
	}
	for (int K = 30; K >= 0; K--) {
		while (bfs(1 << K)) {
			int M = (1 << 30), v = n - 1;
			for (; v; v = fr[v])
				M = min(M, c[fr[v]][v] - f[fr[v]][v]);
			for (v = n - 1; v; v = fr[v])
				f[fr[v]][v] += M,
				f[v][fr[v]] -= M;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (long long)f[0][i];
	printf("%lld\n", ans);
	return 0;
}
