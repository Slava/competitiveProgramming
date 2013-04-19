#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 50000;
int tin[N], tout[N], timer, n, m, root, who[N];
vector<int>g[N];

void dfs(int v) {
	tin[v] = timer++;
	for (int i = 0; i < g[v].size(); i++)
		dfs(g[v][i]);
	tout[v] = timer++;
}

bool p(int x, int y) {
	return tin[x] < tin[y] && tout[x] > tout[y];
}

int X[N], Y[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", X + i, Y + i);
		who[X[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x = X[i], y = Y[i];
		if (y == -1)
			root = i;
		else y = who[y], g[y].push_back(i);
	}
	dfs(root);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = who[x]; y = who[y];
		if (p(x, y))
			printf("1\n");
		else if (p(y, x))
			printf("2\n");
		else printf("0\n");
	}
	return 0;
}
