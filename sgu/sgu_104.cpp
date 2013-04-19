#include <cstdio>
#include <cstdlib>
#define max(a,b) (a>b?a:b)

int a[100][100], n, m, dp[100][100], inf = (1<<30), ans = -inf, an[100];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			dp[i][j] = -inf;
			if (!i) dp[i][j] = a[i][j];
			for (int k = 0; k < j; k++)
				dp[i][j] = max(dp[i][j], a[i][j]+dp[i-1][k]);
			if (i==n-1)
				ans = max(ans, dp[i][j]);
		}

	printf("%d\n", ans);

	int last = m - 1;
	for (int i = n - 1; i >= 0; i--)
		for (; last >= 0; last--)
			if (dp[i][last] == ans) {
				an[i] = last;
				ans -= a[i][last--];
				break;
			}

	for (int i = 0; i < n; i++)
		printf("%d ", an[i] + 1);
	puts("");
	return 0;
}
