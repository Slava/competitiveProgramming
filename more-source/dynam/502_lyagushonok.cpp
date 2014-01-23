#include <cstdio>
#define max(a,b) (a>b?a:b)

int n, a[60][60], d[60][3000];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", a[i] + j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			d[i][j] = -(1 << 30);
	d[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int k = 0; k <= n; k++) {
			for (int j = 0; j < n; j++)
				d[i + 1][k + j + 1] = max(d[i + 1][k + j + 1], d[i][k] + a[j][i]);
			d[i + 1][k] = max(d[i + 1][k], d[i][k]);
		}
	printf("%d\n", d[n][n]);
	return 0;
}
