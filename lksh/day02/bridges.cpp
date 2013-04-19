#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 20100;
vector<int>g[N], e[N], ans;
int n, m, u[N], l[N], d[N];

void bridge(int v) {
	ans.push_back(v);
}

void dfs(int v, int depth, int p) {
	u[v] = 1;
	d[v] = l[v] = depth;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (e[v][i] == p) continue;
		if (u[to])
			l[v] = min(l[v], d[to]);
		else {
			dfs(to, depth + 1, e[v][i]);
			l[v] = min(l[v], l[to]);
			if (d[v] < l[to])
				bridge(e[v][i]);
		}
	}
}

int main() {
#ifndef imslavko
	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
		e[x].push_back(i);
		e[y].push_back(i);
	}
	for (int i = 0; i < n; i++)
		if (!u[i])
			dfs(i, 0, -1);
	sort(ans.begin(), ans.end());
	int nn = unique(ans.begin(), ans.end()) - ans.begin();
	printf("%d\n", nn);
	for (int i = 0; i < nn; i++)
		printf("%d ", ans[i] + 1);
	return 0;
}
