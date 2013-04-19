#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 255;
int n, m, ans;
vector<int>g[N], mt, u;

bool dfs(int v) {
	if (u[v])
		return false;
	u[v] = true;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (mt[to] == -1 || dfs(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {
#ifndef imslavko
	freopen("pairs.in", "r", stdin);
	freopen("pairs.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		do {
			scanf("%d", &x);
			g[i].push_back(x - 1);
		} while(x);
	}
	mt.assign(m, -1);
	for (int i = 0; i < n; i++) {
		u.assign(n, 0);
		ans += dfs(i);
	}
	printf("%d\n", ans);
	for (int i = 0; i < m; i++) 
		if (mt[i] != -1)
			printf("%d %d\n", mt[i] + 1, i + 1);
	return 0;
}
