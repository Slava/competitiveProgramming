#include <cstdio>
#include <cstdlib>
#include <cstring>

struct bigint {
	int n, a[10];
	
	bigint() { make(0); }

	void out() {
		printf("%d", a[n - 1]);
		for (int i = n - 2; i >= 0; i--)
			printf("%09d", a[i]);
	}

	void make(int x) {
		memset(a, 0, sizeof a);
		n = 1; a[0] = x;
	}

	void operator += (bigint &b) {
		int c = 0; n = n > b.n ? n : b.n;
		for (int i = 0; i < n || c; i++) {
			if (i == n) n++;
			a[i] += b.a[i] + c;
			c = a[i] / 1000000000;
			a[i] %= 1000000000;
		}
	}
};

const int N = 85;
int n, len, a[N * 4], m, cur, nxt = 1,
	but[] = {0,1,2,4,5,6,8,9,10,12,13,14,16,17,18,20,21,22,23,24,25,26,28,29,30,31,100},
	first[] = {0,3,6,9,12,15,19,22,26};
char s[N];
bigint dp[2][N][26], ans;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%s", &n, s); len = strlen(s);
	for (int i = 0; i < len; i++)
		for (int j = 0; j <= but[s[i] - 'A'] % 4; j++)
			a[m++] = but[s[i] - 'A'] / 4;
	dp[0][0][first[a[0]]].make(1);
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 26; k++)
				dp[nxt][j][k].make(0);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 26; k++) {
				int bt = a[i + 1], c = first[bt];
				dp[nxt][j + 1][c] += dp[cur][j][k];
				if (but[k] / 4 == bt && but[k + 1] / 4 == bt)
					dp[nxt][j][k + 1] += dp[cur][j][k];
			}
		nxt ^= 1; cur ^= 1;
	}
	for (int i = 0; i < 26; i++)
		ans += dp[cur][n - 1][i];
	ans.out();
	return 0;
}
