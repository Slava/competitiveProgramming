#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

const int N = 100100;
int n, m, u[N];
vector<int> g[N], l;

bool dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (u[to] == 1)
			return 1;
		if (!u[to] && dfs(to))
			return 1;
	}
	u[v] = 2;
	l.push_back(v + 1);
	return 0;
}

int main() {
#ifndef imslavko
	freopen("topsort2.in", "r", stdin);
	freopen("topsort2.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].push_back(y);
	}
	for (int i = 0; i < n; i++)
		if (!u[i] && dfs(i)) {
			printf("-1\n");
			return 0;
		}
	for (int i = (int)l.size() - 1; i >= 0; i--)
		printf("%d ", l[i]);
	return 0;
}
