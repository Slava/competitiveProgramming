#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200100;
int n, m, ch[N], u[N], cnt, Not[N], ans[N];
vector<int>g[N], bg[N], ls;

void topsort(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (!u[to])
			topsort(to);
	}
	ls.push_back(v);
}

void dfs(int v) {
	u[v] = cnt;
	for (int i = 0; i < (int)bg[v].size(); i++) {
		int to = bg[v][i];
		if (!u[to])
			dfs(to);
	}
}

int main() {
#ifndef imslavko
	freopen("contest.in", "r", stdin);
	freopen("contest.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		Not[x] = y; Not[y] = x;
	}
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		g[x].push_back(Not[y]); g[y].push_back(Not[x]);
		bg[Not[y]].push_back(x); bg[Not[x]].push_back(y);
	}
	for (int i = 0; i < n * 2; i++)
		if (!u[i])topsort(i);
	reverse(ls.begin(), ls.end());
	memset(u, 0, sizeof u);
	for (int i = 0; i < (int)ls.size(); i++)
		if(!u[ls[i]]) {
			cnt++;
			dfs(ls[i]);
		}
	for (int i = 0; i < n * 2; i++)
		if (u[i] == u[Not[i]]) {
			printf("-1\n"); return 0;
		}
		else if (u[i] > u[Not[i]])
			ans[i] = 1;
		else ans[Not[i]] = 1;
	for (int i = 0; i < 2 * n; i++)
		if (ans[i]) printf("%d ", i + 1);
	return 0;
}
