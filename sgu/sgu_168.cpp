#include <cstdio>

const int N = 1010;
int n, m;
int a[N][N], i, j;
#define upd(a,b) if(a>b)a=b;
int main() {
	scanf("%d%d", &n, &m);
	for (i = 0; i < n + 2; ++i)
		for (j = 0; j < m + 2; ++j)
			a[i][j] = 10000000;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			scanf("%d", a[i] + j);
	for (j = m; j >= 1; --j)
		for (i = n; i >= 1; --i) {
			upd(a[i][j], a[i - 1][j + 1]);
			upd(a[i][j], a[i + 1][j]);
			upd(a[i][j], a[i][j + 1]);
			upd(a[i][j], a[i + 1][j + 1]);
		}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}

