#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int n, m, k, u[1010], mt[1010], A, sw;
vector<int>g[1010];

bool dfs(int v) {
	if (u[v])return false;
	u[v] = true;
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++)
		if (!mt[*i] || dfs(mt[*i])) {
			mt[*i] = v;
			return true;
		}
	return false;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	if (n > m) {
		swap(m, n);
		sw = 1;
	}
	for (int i = 0, x, y; i < k; i++) {
		scanf("%d%d", &x, &y);
		if (sw) swap(x, y);
		g[x].push_back(y); 
	}
	for (int i = 1; i <= n; i++) {
		memset(u, 0, sizeof u);
		A += dfs(i);
	}
	printf("%d\n", n - A + m);
	return 0;
}

