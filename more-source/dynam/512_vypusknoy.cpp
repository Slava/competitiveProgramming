#include <cstdio>
#include <cstdlib>

int n, m, k, a[11][11], dp[12][1 << 10], ans;
char s[11];

int bitcnt(int x) {
	int c = 0;
	for (; x; x &= x - 1)
		c++;
	return c;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			a[i][j] = s[j] == 'Y';
	}

	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < (1 << m); j++)
			if (dp[i][j]) {
				for (int l = 0; l < m; l++)
					if (!((j>>l)&1))
						if (a[i][l])
							dp[i + 1][j + (1 << l)] += dp[i][j];
				dp[i + 1][j] += dp[i][j];
				if (i == n && bitcnt(j) == k)
					ans += dp[n][j];
			}
	
	printf("%d\n", ans);

	return 0;
}
