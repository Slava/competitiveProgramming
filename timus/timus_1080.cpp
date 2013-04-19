#include <cstdio>

const int N = 100;
int n, x;
bool a[N][N], u[N], c[N], bad;

void dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < n; i++)
		if (a[v][i]) if(!u[i]) {
			c[i] = c[v] ^ 1;
			dfs(i);
		} else if (c[v] == c[i])
			bad = 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		while(true) {
			scanf("%d", &x);
			if (!x)
				break;
			a[i][x-1] = a[x-1][i] = 1;
		}
	}

	dfs(0);

	if (bad)
		printf("-1\n");
	else
		for (int i = 0; i < n; i++)
			printf("%d", c[i]);

	return 0;
}

