#include <cstdlib>
#include <cstdio>

int a[210][210], u[210], c[210], ans, n, m;
void dfs(int v) {
	u[v] = 1; if (!c[v]) ans++;
	for (int i = 1; i <= n; i++)
		if (a[v][i])
			if (!u[i]) {
				c[i] = c[v] ^ 1;
				dfs(i);			
			}
			else if (c[i] != c[v] ^ 1) {
				printf("no");
				exit(0);
			}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = a[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) 
		if (!u[i])
			dfs(i);
	printf("yes\n%d\n", ans);
	for (int i = 1; i <= n; i++)
		if (!c[i])
			printf("%d ", i);
	return 0;
}

