#include <cstdio>
#include <cstdlib>
#include <cstring>

bool pal[4010][4010];
int n, dp[4010], to[4010];
char s[4010];

int get(int i) {
	if (dp[i])return dp[i];
	if (pal[i][n - 1]) {
		to[i] = n;
		return dp[i] = 1;
	}
	dp[i] = (1 << 30);
	for (int k = i; k < n; k++)
		if (pal[i][k]) {
			int v = get(k + 1);
			if (dp[i] > v + 1) {
				dp[i] = v + 1;
				to[i] = k + 1;
			}
		}
	return dp[i];
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int j = 0; j < n; j++)
		for (int i = 0; i + j  < n; i++)
			if (j < 2 && s[i] == s[j + i])
				pal[i][j + i] = 1;
			else if (s[i] == s[j + i] && pal[i + 1][i + j - 1])
				pal[i][i + j] = 1;
	printf("%d\n", get(0));
	for (int i = 0; i < n; i = to[i]) {
		for (int j = i; j < to[i]; j++)
			printf("%c", s[j]);
		printf(" ");
	}
	printf("\n");
	return 0;
}
