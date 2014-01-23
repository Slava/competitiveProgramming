#include <cstdio>
#include <cstdlib>

const int N = 310;
int n, m, a[N][N], ans;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = int(1e6);

	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[x][y] = 0;
		if (a[y][x])
			a[y][x] = 1;
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (ans < a[i][j] && a[i][j] != int(1e6))
				ans = a[i][j];

	printf("%d\n", ans);

	return 0;
}
