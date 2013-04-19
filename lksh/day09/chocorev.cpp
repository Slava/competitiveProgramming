#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 200100;
int n, c[N], d[N], u[N];
vector<int>g[N];

int dfs(int v, int C) {
	if (u[v]) return d[v];
	u[v] = 1;
	d[v] = c[v];
	if (C) if (!g[v].empty())
		d[v] = (1 << 30);
	for (int i = 0; i < (int)g[v].size(); i++)
		if (C) d[v] = min(d[v], dfs(g[v][i], 0));
		else d[v] = max(d[v], dfs(g[v][i], 1));
	return d[v];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d%d", &x, c + i);
		g[x].push_back(i);
	}
	printf("%d\n", dfs(1, 0));
	return 0;
}
