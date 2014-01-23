// imslako
#include <cstdio>
#include <cstdlib>

#define min(a,b) (a<b?a:b)
const int N = 155;
int n, m, a[N][N], d[N][N], root, r[N][N], inf = 1 << 30, ans = inf;

void dfs(int v, int p = -1) {
	int cnt = 0, j = 0;
	for (int i = 0; i < n; i++)
		if (i != p && a[v][i])
			dfs(i, v), cnt++;
	for (int i = 0; i <= cnt; i++)
		for (int k = 0; k <= m; k++)
			r[i][k] = inf;
	d[v][0] = 1;
	r[0][1] = 0;
	for (int i = 0; i < cnt; i++) {
		while (!a[v][j] || p == j)
			j++;
		for (int k = 0; k <= m; k++)
			if (d[j][k] != inf)
				for (int it = m - k; it >= 0; it--)
					r[i + 1][it + k] = min(r[i + 1][it + k], r[i][it] + d[j][k]);
		j++;
	}
	for (int i = 1; i <= m; i++)
		d[v][i] = r[cnt][i];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--; a[x][y] = a[y][x] = 1;
	}

//	root = rand() % n;
	dfs(root); ans = d[root][m];

	printf("%d\n", ans);

	return 0;
}
