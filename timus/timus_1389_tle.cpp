#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back
int n, m, res, u[101010], mt[101010], c[101010];
vector<int>g[101010], w, b;

void dfs(int v, int p) {
	c[v] = c[p] ^ 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != p)
			dfs(to, v);
	}
}

bool kuhn(int v) {
	if (u[v])
		return false;
	u[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (mt[to] == -1 || kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {
	memset(mt, -1, sizeof mt);
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		g[x].pb(y); g[y].pb(x);
	}
	int root = rand() % n;
	dfs(root, root);
	w.reserve(n); b.reserve(n);
	for (int i = 0; i < n; i++)
		if (c[i])
			w.pb(i);
		else b.pb(i);
	vector<int> &a = (w.size() < b.size()) ? w : b;
	for (int i = 0; i < a.size(); i++) {
		memset(u, 0, sizeof u);
		res += kuhn(a[i]);
	}
	printf("%d\n", res);
	for (int i = 0; i < n; i++)
		if (mt[i] != -1)
			printf("%d %d\n", i + 1, mt[i] + 1);
	return 0;
}

