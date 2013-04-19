#include <cstdio>
#include <cstring>

int dp[910][8110], len[910][8110], out;
char *s, output[200];

bool go(int n, int m) {
	if (!n && !m) 
		return true;
	if (dp[n][m] != -1) {
		if (!dp[n][m])return false;
		if (out) {
			printf("%d", dp[n][m]);
			go(n - dp[n][m], m - dp[n][m] * dp[n][m]);
		}
		return true;
	}
	dp[n][m] = 0; len[n][m] = (1 << 30);
	for (int i = 9; i > 0; i--)
		if (n >= i && m >= i * i && go(n - i, m - i * i)) {
			if (len[n][m] >= len[n - i][m - i * i] + 1) {
				len[n][m] = len[n - i][m - i * i] + 1;
				dp[n][m] = i;
			}
		}
	if (len[n][m] == (1 << 30))
		return false;
	return true;
}

int main() {
	int t; memset(dp, -1, sizeof dp);
	scanf("%d", &t);
	for (int n, m; t--; ) {
		scanf("%d%d", &n, &m);
		out = 0; s = output;
		if (n > 900 || m > 8100 || !go(n, m) || len[n][m] > 100)
			printf("No solution");
		else {
			out = 1; go(n, m);			
		}
		printf("\n");
	}
	return 0;
}

