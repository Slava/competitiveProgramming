#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, m, a[110][110], u[110], p[110], w[110], k, best[110], Max, pb[110];
int toout[110];

void dfs(int v) {
	u[v] = true;
	w[v] = 1;
	for (int i = 0; i < n; i++)
		if (a[v][i] && !u[i]) {
			p[i] = v;
			dfs(i);
			w[v] += w[i];
		}
}

void solve(int v) {
	memset(u, 0, sizeof u);
	p[v] = v;
	dfs(v);
	memset(u, 0, sizeof u);
	int cnt = 0;
	for (int left = n; left > 0; ) {
		int mn = -1;
		for (int i = 0; i < n; i++)
			if (w[i] > k && !u[i] && (mn == -1 || w[i] < w[mn]))
				mn = i;
		if (mn == -1)
			break;
		u[mn] = ++cnt;
		int V = p[mn];
		while (V != v) {
			w[V] -= w[mn];
			V = p[V];
		}
		w[v] -= w[mn];

		left -= w[mn];
	}

	if (cnt > Max) {
		Max = cnt;
		for (int i = 0; i < n; i++)
			best[i] = u[i], pb[i] = p[i];
	}
}

void output(int v) {
	u[v] = true;
	toout[k++] = v;
	for (int i = 0; i < n; i++)
		if (a[v][i] && !u[i] && pb[v] != i)
			output(i);
}

int main() {
	freopen("rep.in", "r", stdin);
	freopen("rep.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		a[x][y] = a[y][x] = 1;
	}

	scanf("%d", &k);

	for (int i = 0; i < n; i++)
		solve(i);
	
	printf("%d\n", Max);

	memset(u, 0, sizeof u);
	for (int i = 1; i <= Max; i++) {
		k = 0;
		for (int j = 0; j < n; j++)
			if (best[j] == i) {
				output(j); break;
			}
		if (i == Max)
			for (int j = 0; j < n; j++)
				if (!u[j]) toout[k++] = j;
		printf("%d", k);
		for (; k > 0; k--) printf(" %d", toout[k - 1] + 1);
		puts("");
	}

	return 0;
}
