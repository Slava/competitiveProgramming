#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3100;
int n, m, u[N], cnt, out[N];
vector<int>g[N], bg[N], ls, ans;

void dfs(int v) {
	u[v] = cnt;
	for (int i = 0; i < (int)bg[v].size(); i++) {
		int to = bg[v][i];
		if (!u[to])
			dfs(to);
	}
}

void topsort(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (!u[to])
			topsort(to);
	}
	ls.push_back(v);
}

int main() {
#ifndef imslavko
	freopen("firesafe.in", "r", stdin);
	freopen("firesafe.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0, x, y; i < m; i++) {
		scanf("%d%d", &x, &y); x--; y--;
		bg[y].push_back(x);
		g[x].push_back(y);
	}
	for (int i = 0; i < n; i++)
		if (!u[i])
			topsort(i);
	reverse(ls.begin(), ls.end());
	memset(u, 0, sizeof u);
	for (int i = 0; i < (int)ls.size(); i++)
		if (!u[ls[i]]) {
			cnt++; dfs(ls[i]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)g[i].size(); j++) {
			int to = g[i][j];
			if (u[to] != u[i])
				out[u[i]] = 1;
		}
	for (int i = 0; i < n; i++)
		if (!out[u[i]]) {
			ans.push_back(i);
			out[u[i]] = 1;
		}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i] + 1);
	return 0;
}
