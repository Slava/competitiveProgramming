#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 120;
int n, m, s, d[N][N];

int get(int n, int m) {
	if (n > m)
		n += m, m = n - m, n -= m;
	if (n == 1 && m <= s)
		return 0;
	if (d[n][m] != -1)
		return d[n][m];
	bool a[N * N];
	memset(a, 0, sizeof a);
	for (int i = 1; i < n; i++)
		a[get(m, i) ^ get(m, n - i)] = 1;
	for (int i = 1; i < m; i++)
		a[get(n, i) ^ get(n, m - i)] = 1;
	d[n][m] = 0;
	while (a[d[n][m]])
		d[n][m]++;
	return d[n][m];
}

int main() {
	memset(d, -1, sizeof d);
	scanf("%d%d%d", &n, &m, &s);
	printf("%d\n", get(n, m) ? 1 : 2);
	return 0;
}
