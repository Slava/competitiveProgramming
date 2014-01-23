#include <cstdio>

const int N = 210;
int n, m, k, d[] = {0,1,1,0,0,-1,-1,0,1,1,-1,-1,-1,1,1,-1};
char a[N][N], s[N];
long long dp[N][N][110];

int main() {
	freopen("grid.in", "r", stdin);
	freopen("grid.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == s[0])
				dp[i][j][0] = 1;

	for (int l = 0; l < k - 1; l++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int o = 0; o < 16; o += 2) {
					int di = i + d[o], dj = j + d[o+1];
					if (di >= 0 && di < n && dj >= 0 && dj < m && a[di][dj] == s[l+1])
						dp[di][dj][l+1] += dp[i][j][l];
				}

	long long sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += dp[i][j][k-1];

/*
	for (int l = 0; l < k; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
				printf("%lld ", dp[i][j][l]);
			puts("");
		}
		puts("");
	}
*/

	printf("%lld\n", sum);

	return 0;
}

