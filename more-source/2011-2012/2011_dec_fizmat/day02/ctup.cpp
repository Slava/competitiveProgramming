#include <cstdio>
#include <cstdlib>

const int N = 10001000;
int x[N], y[N], z[N], n;

int dist(int i, int j) {
	return abs(x[i] - y[j]) + abs(y[i] - z[j]) + abs(z[i] - x[j]);
}

int main() {
	freopen("metro.in", "r", stdin);
	freopen("metro.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", x + i, y + i, z + i);
	int ans = 0, ansi, ansj;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) if (i != j)
			if (ans <= dist(i,j)) {
				ans = dist(i,j);
				ansi = i;
				ansj = j;
			}
	printf("%d\n%d %d\n", ans, ansi + 1, ansj + 1);
	return 0;
}
