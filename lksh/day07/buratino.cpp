#include <cstdio>
#include <cstdlib>


const int S = 3600, N = S * 18 + 10;
int n, a[N], b[N], c[N], d[N], j;

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		int h, m, s, t;
		scanf("%d:%d:%d %d\n", &h, &m, &s, &t);
		a[i] = h * S + m * 60 + s; b[i] = t;
	}
	for (int i = S * 9; i <= S * 18; i++) {
		int k = c[i];
		if (a[j] == i)
			k = b[j++];
		if (i + k <= S * 18 && ((i < 13 * S && i + k <= 13 * S) || (i >= 14 * S && i + k >= 14 * S))) {
			if (d[i + k] < d[i] + 1)
				d[i + k] = d[i] + 1;
			c[i + k] = k;
		}
		if (d[i + 1] < d[i])
			d[i + 1] = d[i];
		c[i + 1] = k;
	}
	printf("%d\n", d[S * 18]);
	return 0;
}
