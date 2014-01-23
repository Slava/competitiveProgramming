#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 10000;
int n, m, cutPoint[N], u[N], tin[N], fup[N], timer;
vector<int> g[N];

void dfs(int v, int p = -1) {
	u[v] = 1;
	tin[v] = fup[v] = timer++;
	int children = 0;

	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (p != to)
			if (u[to])
				fup[v] = min(tin[to], fup[v]);
			else {
				dfs(to, v);
				fup[v] = min(fup[v], fup[to]);
				if (fup[to] >= tin[v])
					cutPoint[v] = true;
				children++;
			}
	}
	if (p == -1 && children > 1)
		cutPoint[v] = true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0);
	for (int i = 0; i < n; i++)
		if (cutPoint[i])
			printf("%d ", i + 1);

	return 0;
}
