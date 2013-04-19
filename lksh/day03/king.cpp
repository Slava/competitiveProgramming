#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 4010;
int n, k, x, u[N], mt[N], ans[N][N], comp;
vector<int> g[N], a[N], ls, bg[N];

void dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (!u[to])
			dfs(to);
	}
	ls.push_back(v);
}

void col(int v) {
	u[v] = comp;
	for (int i = 0; i < (int)bg[v].size(); i++) {
		int to = bg[v][i];
		if (!u[to])
			col(to);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &x); x--;
			a[i].push_back(x);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); x--;
		mt[x] = i; ans[i][n + x] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)a[i].size(); j++) {
			int to = a[i][j];
			if (mt[to] != i)
				g[i].push_back(to + n),
				bg[to + n].push_back(i);
		}
	for (int i = 0; i < n; i++)
		g[i + n].push_back(mt[i]), bg[mt[i]].push_back(i + n);
	for (int i = 0; i < n * 2; i++)
		if (!u[i]) dfs(i);
	memset(u, 0, sizeof u);
	reverse(ls.begin(), ls.end());
	for (int i = 0; i < (int)ls.size(); i++) {
		int to = ls[i];
		if (!u[to]) {
			comp++; col(to);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)g[i].size(); j++) {
			int to = g[i][j];
			ans[i][to] |= (u[i] == u[to]);
		}
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 0; j < n; j++)
			k += ans[i][j + n];
		printf("%d ", k);
		for (int j = 0; j < n; j++)
			if (ans[i][j + n])
				printf("%d ", j + 1);
		printf("\n");
	}
	return 0;
}
