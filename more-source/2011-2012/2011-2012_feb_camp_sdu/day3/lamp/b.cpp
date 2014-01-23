#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n, m, ans = 1<<30, N;
char s[600][600];
bool u[300];
vector<vector<int> > g;

void dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
		if (!u[g[v][i]])
			dfs(g[v][i]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	N = (n + 1) * (m + 1);

	for (int mask = 0; mask < (1<<(n*m)); mask++) {
		g.assign((n+1)*(m+1), vector<int>());
		memset(u, 0, sizeof u);
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if ((s[i][j] == '/') ^ (1&(mask>>(i*m+j)))) {
					g[i*(m+1)+j+1].push_back((i+1)*(m+1)+j),
					g[(i+1)*(m+1)+j].push_back(i*(m+1)+j+1);
				}
				else {
					g[i*(m+1)+j].push_back((i+1)*(m+1)+j+1),
					g[(i+1)*(m+1)+j+1].push_back(i*(m+1)+j);
				}
				cnt += (mask>>(i*m+j))&1;
			}
		dfs(0);
		if (u[N-1])
			if (ans > cnt)
				ans = cnt;
	}

	if (ans != 1<<30)
	printf("%d\n", ans);
	else puts("NO SOLUTION");

	return 0;
}

