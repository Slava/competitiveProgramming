#include <cstdio>
#include <cstdlib>

int n, m, a[10010], u[10010], g[60];
int dfs(int v) {
	if (u[v]) return a[v];
	u[v] = 1;
	for (int i = 0; i < m; i++) {
		if (v - g[i] < 0) continue;
		int w = dfs(v - g[i]);
		if (!w) a[v] = 1;
	}
	return a[v];
}

/* START */
int main (){
	scanf("%d%d", &n, &m);
	u[0] = a[0] = 1;
	for (int i = 0; i < m; i++)
		scanf("%d", g + i);
	if (dfs(n))printf("1");
	else printf("2");
	return 0;
}
