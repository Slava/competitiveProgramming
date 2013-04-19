#include <cstdio>

int q[10100], h, t, a[100][100], n, d[] = {0, -1, 1, 0}, c;
int main() {
	scanf("%d", &n);
	q[t++] = n - 1;
	a[0][n - 1] = ++c;
	while (h < t) {
		int x = q[h] / 100, y = q[h++] % 100;
		for (int i = 0; i < 4; i += 2) {
			int dx = x + d[i], dy = y + d[i + 1];
			if (dx < n && dy >= 0 && !a[dx][dy]) {
				q[t++] = dx * 100 + dy;
				a[dx][dy] = ++c;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", a[i][j], " \n"[j == n - 1]);
	return 0;
}

