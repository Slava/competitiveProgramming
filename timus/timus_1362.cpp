#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:100000000")

using namespace std;

int n, root;
vector<int>g[100010];
int dfs(int v, int p = -1) {
	vector<int>t;
	t.reserve(g[v].size());
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != p)
			t.push_back(dfs(g[v][i], v));
	if (t.empty())
		return 0;
	sort(t.begin(), t.end());
	int an = 0;
	for (int i = 0; i < t.size(); i++)
		an = max(an, t[i] + (int)t.size() - i);
	return an;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		for (scanf("%d", &x); x; scanf("%d", &x)) {
			g[i].push_back(x);
			g[x].push_back(i);
		}
	}
	scanf("%d", &root);
	printf("%d\n", dfs(root));
	return 0;
}

