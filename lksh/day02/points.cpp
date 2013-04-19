#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 20100;
vector<int>g[N];
int n, m, u[N], l[N], d[N], timer, po[N];


void dfs(int v, int p) {
	u[v] = 1; int c = 0;
	d[v] = l[v] = timer++;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (to == p) continue;
		if (u[to])
			l[v] = min(l[v], d[to]);
		else {
			dfs(to, v);
			l[v] = min(l[v], l[to]);
			if (l[to] >= d[v] && p != -1)
				po[v] = 1;
			c++;
		}
	}
	if (c > 1 && p == -1)
		po[v] = 1;
}

int main() {
#ifndef imslavko
	freopen("points.in", "r", stdin);
	freopen("points.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	m = 0;
	for (int i = 0; i < n; i++)
		if (!u[i])
			dfs(i, -1);
	for (int i = 0; i < n; i++)
		m += po[i];
	printf("%d\n", m);
	for (int i = 0; i < n; i++)
		if (po[i])
			printf("%d\n", i + 1);
	return 0;
}
