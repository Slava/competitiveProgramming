#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 110;
vector<int> g[N];
int n, m, dp[N][N][N], inf = int(1e9), k;
bool u[N][N][N];

int dfs(int v, int l, int need) {
	if (u[v][l][need])
		return dp[v][l][need];
	u[v][l][need] = 1;
	int &res = dp[v][l][need];
	if (l == (int)g[v].size()) {
		if (!need)return 1;
		return -inf;
	}

	for (int i = k; i < n; i++)
		if (dfs(v, l + 1, need) != -inf &&
			dfs(g[v][l], 0, i) != -inf)
			res = max(res, dfs(v, l + 1, need)
				   	+ dfs(g[v][l], 0, i));

	for (int i = 0; i < need; i++)
		if (dfs(g[v][l], 0, i) != -inf &&
			dfs(v, l + 1, need - 1 - i) != -inf)
			res = max(res, dfs(g[v][l], 0, i)
				   	+ dfs(v, l + 1, need - 1 - i) - 1);

	return res;
}

void dfs1(int v) {
	for (int i = 0; i < (int)g[v].size(); i++) {
		for (int j = 0; j < (int)g[g[v][i]].size(); j++)
			if (g[g[v][i]][j] == v) {
				g[g[v][i]].erase(g[g[v][i]].begin() + j);
				break;
			}
		dfs1(g[v][i]);
	}
}

int main() {
	
	return 0;
}
