#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 1010;
int a[N][N], st[101010], k, n, m, x, pw[N], f, odd;

void dfs(int v) {
	for (int i = 0; i < n; i++)
		if (a[v][i]) {
			a[v][i]--; a[i][v]--;
			pw[v]--; pw[i]--;
			dfs(i);
		}
	st[k++] = v;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d%d", &x, &k); x--;
			a[i][x]++; pw[i]++;
			f = x;
		}
	}
	
	for (int i = 0; i < n; i++)
		if (pw[i] & 1) {
			odd++; f = i;
		}
	k = 0;
	if (odd > 2) {
		printf("-1\n");
		return 0;
	}
	dfs(f);
	for (int i = 0; i < n; i++)
		if (pw[i]) {
			printf("-1\n");
			return 0;
		}
	printf("%d\n", k - (k != 1));
	for (int i = 0; i < k; i++)
		printf("%d ", st[i] + 1);
	return 0;
}
