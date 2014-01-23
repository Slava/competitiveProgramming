#include <cstdio>

int a[20][20][32], n, k, d[] = {0,1,0,-1,1,0,-1,0};
char c[20][20];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", c[i]);

	a[0][0][0] = 1;
	for (int l = 0; l < k; l++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int p = 0; p < 8; p += 2) {
					int x = i + d[p], y = j + d[p + 1];
					if (x < 0 || x >= n || y < 0 || y >= n || c[x][y] == '1')
						continue;
					a[x][y][l + 1] += a[i][j][l];
				}
	printf("%d\n", a[n - 1][n - 1][k]);
	return 0;
}
