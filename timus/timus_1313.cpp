#include <cstdio>

int n, a[100][100], u[100][100];
int q[10000], h, t, d[] = {1, 0, 0, 1};
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			scanf("%d", a[i] + j);
	q[t++] = 0;
	while (h < t) {
		int x = q[h] / n, y = q[h++] % n;
		printf("%d ", a[x][y]);
		for (int i = 0; i < 4; i += 2) {
			int dx = x + d[i], dy = y + d[i + 1];
			if (dx < n && dy < n && !u[dx][dy]) {
				u[dx][dy] = 1;
				q[t++] = dx * n + dy;
			}
		}
	}
	return 0;
}

