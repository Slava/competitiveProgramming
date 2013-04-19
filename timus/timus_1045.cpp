#include <cstdio>
#include <cstdlib>

int n, k, x, y, a[1010][1010], u[1010];

int dfs(int v) {
	u[v] = 1;
	int ww = 0;
	for (int i = 1; i <= n; i++)
		if(a[v][i] && !u[i]) {
			int w = dfs(i);
			if (!w && !ww) ww = i;
		}
	return ww;
}

/* START */
int main (){
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[x][y] = a[y][x] = 1;
	}
	int w = dfs(k);
	if (w)
		printf("First player wins flying to airport %d", w);
	else printf("First player loses");
	return 0;
}
