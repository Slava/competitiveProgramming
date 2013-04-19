#include <cstdio>
#include <cstdlib>
#define bit(x,y) (((x)>>(y))&1)

const int PR = 1 << 7, N = 40;
int n, m, a[PR][PR], d[N][PR], ans, twon;

bool good(int m, int k) {
	for (int i = 1; i < n; i++)
		if (bit(m, i - 1) == bit(m, i) &&
			bit(k, i - 1) == bit(k, i) &&
			bit(k, i) == bit(m, i))
			return 0;
	return 1;
}

int main() {
#ifndef imslavko
	freopen("nice.in", "r", stdin);
	freopen("nice.out", "w", stdout);
#endif
	
	scanf("%d%d", &n, &m);
	if (n > m)
		n += m, m = n - m, n -= m;
	twon = 1 << n;
	for (int i = 0; i < twon; i++) {
		for (int j = i; j < twon; j++)
			a[i][j] = a[j][i] = good(i, j);
		d[0][i] = 1;
	}
	for (int i = 1; i < m; i++)
		for (int j = 0; j < twon; j++)
			for (int k = 0; k < twon; k++)
				d[i][j] += d[i - 1][k] * a[j][k];
	for (int i = 0; i < twon; i++)
		ans += d[m - 1][i];
	printf("%d\n", ans);
	return 0;
}
