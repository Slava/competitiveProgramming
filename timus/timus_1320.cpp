#include <cstdio>
#include <cstdlib>

int u[1010], a[1010][1010], n = 1001, num;

void dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < n; i++)
		 if (a[v][i]) {
		 	num++; a[v][i]--; a[i][v]--;
			if (!u[i])
				dfs(i);
		 }
}
int main() {
	for (int x, y; scanf("%d%d", &x, &y) == 2; ) 
		a[x][y] = a[y][x] = 1;
	for (int i = 0; i < n; i++)
		if (!u[i]) {
			num = 0;
			dfs(i);
			if (num & 1) {
				printf("0");
				return 0;
			}
		}
	printf("1");
	return 0;
}
