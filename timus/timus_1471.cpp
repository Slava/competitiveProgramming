#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

#pragma comment(linker, "/STACK:16777216")

#define pb push_back
const int N = 50100;
int n, m, u[N], l[N], dist[N], list[N * 2], ln, f[N], d[2 * N][30], lg[2 * N];
vector<int> g[N], a[N];

void dfs(int v, int d = 0, int di = 0) {
	u[v] = 1; l[v] = d; dist[v] = di;
	list[ln++] = v;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (!u[to]) {
			dfs(to, d + 1, di + a[v][i]);
			list[ln++] = v;
		}
	}
}

int min_h(int i, int j) {
	return l[i] < l[j] ? i : j;
}

void build_st() {
	for (int i = 0; i < ln; i++)
		d[i][0] = list[i];
	for (int j = 1; (1 << j) <= ln; j++)
		for (int i = 0; i + (1 << j) <= ln; i++)
			d[i][j] = min_h(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}

int getmin(int l, int r) {
	if (l > r) swap(l, r);
	int k = lg[r - l + 1];
	return min_h(d[l][k], d[r + 1 - (1 << k)][k]);
}

int main (){
	scanf("%d", &n);
	for (int i = 1, x, y, z; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		g[x].pb(y); a[x].pb(z); g[y].pb(x); a[y].pb(z);
	}	
	for (int i = 1; i <= n * 4; i++) {
		lg[i] = (int)(log(i + .0)/log(2.)); 
	}
	dfs(0); build_st();
	for (int i = ln - 1; i >= 0; i--)
		f[list[i]] = i;
	scanf("%d", &m);
	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d%d", &x, &y);
		z = getmin(f[x], f[y]);
		printf("%d\n", dist[x] + dist[y] - dist[z] * 2);
	}
	return 0;
}
