#pragma comment(linker, "/STACK:256000000")
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

const int N = 50100;
int salary[N], size[N], X[N], Y[N], u[N];
vector<int> g[N], gw[N];
int n, m, pl[N], Min;

bool dfs(int v, int U) {
	u[v] = U;
	Min = min(salary[v], Min);
	for (int i = 0; i < size[v]; i++) {
		int to = g[v][i], w = gw[v][i];
		if (u[to] > 0 && salary[to] != salary[v]+w)
			return 1;
		salary[to] = salary[v] + w;
		if (!u[to] && dfs(to, U))
			return 1;
	}
	return 0;
}

bool solve(int st, bool output=0) {
	memset(size, 0, sizeof size);
	memset(u, 0, sizeof u);
	memset(salary, 0, sizeof salary);
	memset(pl, 0, sizeof pl);
	for (int i = 0; i < st; i++)
		size[X[i]]++, size[Y[i]]++;
	
	int M = 0;
	Min = 1<<30;
	if (dfs(0,++M)||Min < 0)
		return 0;
	for (int i = 0; i < n; i++)
		if (!u[i]) {
			Min = 1<<30;
			if(dfs(i,++M))
				return 0;
			pl[M] = Min;
		}
	
	for (int i = 0; i < n; i++)
		salary[i] -= pl[u[i]];

	if (output) {
		puts("Possible");
		for (int i = 0; i < n; i++)
			printf("%d\n", salary[i]);
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		scanf("%d%d%d", &y, &x, &w);
		g[x].push_back(y);
		gw[x].push_back(w);
		g[y].push_back(x);
		gw[y].push_back(-w);
		X[i] = x; Y[i] = y;
	}

	if (solve(m,1))
		return 0;
	int l = 1, r = m, mid;
	while(l<=r) {
		mid = (l+r) / 2;
		if (solve(mid))
			l = mid+1;
		else r = mid-1;
	}

	printf("Impossible after %d statements\n", l);

	return 0;
}

