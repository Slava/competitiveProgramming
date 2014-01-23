#include <cstdio>

const int N = 40;
int n, a[N], b[N], c[N], d[N], e[N];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	a[0] = 1; 
	scanf("%d", &n);
	if (n & 1) {
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i + 1] += b[i] + c[i];
		a[i + 2] += a[i];
		b[i + 1] += a[i] + d[i];
		c[i + 1] += a[i] + e[i];
		d[i + 1] += b[i];
		e[i + 1] += c[i];
	}
	printf("%d\n", a[n]);

	return 0;
}
