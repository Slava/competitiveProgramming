#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, c, k, a[N][N], b[N], inf = 101010, ans[N], an;
int main() {
#ifndef imslavko
	freopen("mincoin1.in", "r", stdin);
	freopen("mincoin1.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &c, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", b + i);
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= c; j++)
			a[i][j] = inf;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= c; j++) {
			if (a[i][j + b[i - 1]] > a[i - 1][j] + 1)
				a[i][j + b[i - 1]] = a[i - 1][j] + 1;
			if (a[i][j] > a[i - 1][j])
				a[i][j] = a[i - 1][j];
		}
	if (a[n][c] == inf) {
		printf("-1\n");
		return 0;
	}
	int x = n, y = c;
	while (y || x) {
		if (y - b[x - 1] >= 0 && a[x][y] == 1 + a[x - 1][y - b[x - 1]]) {
			ans[an++] = x;
			y -= b[x - 1];
		}
		x--;
	}
	sort(ans, ans + an);
	printf("%d\n", an);
	for (int i = 0; i < an; i++)
		printf("%d ", ans[i]);
	return 0;
}
