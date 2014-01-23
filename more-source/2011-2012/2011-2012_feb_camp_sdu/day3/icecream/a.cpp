#include <cstdio>
#include <cassert>

const int N = 220;

bool a[N][N];
int n, m, ans;

int main() {
	assert(scanf("%d%d", &n, &m)==2);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x-1][y-1] = a[y-1][x-1] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
				if (!a[i][j] && !a[j][k] && !a[i][k])
					ans++;

	printf("%d\n", ans);

	return 0;
}
