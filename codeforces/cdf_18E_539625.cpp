#include <cstdio>
#include <cstring>

int n, m, t, v, c[26][26], e[26], o[26];
int dp[510][26][26], fr[510][26][26], ans[510];
char s[510][510];

void count(int Y) {
	memset(e, 0, sizeof e);
	memset(o, 0, sizeof o);
	memset(c, 0, sizeof c);
	for (int i = 0; i < m; i++)
		if (i & 1)
			o[s[Y][i] - 'a']++;
		else e[s[Y][i] - 'a']++;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			if (i != j)
				c[i][j] = m - e[i] - o[j];
}

void out(int i, int v) {
	if (i) out(i - 1, fr[i][v / 26][v % 26]);
	for (int j = 0; j < m; j++)
		if (j & 1)
			printf("%c", 'a' + v % 26);
		else printf("%c", 'a' + v / 26);
	printf("\n");
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	count(0);
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			dp[0][i][j] = c[i][j];
	for (int k = 1; k < n; k++) {
		count(k);
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++) if (i != j) {
				dp[k][i][j] = (1 << 30);
				for (int A = 0; A < 26; A++) if (A != i)
					for (int B = 0; B < 26; B++) if (B != A && B != j)
						if (dp[k][i][j] > dp[k - 1][A][B] + c[i][j]) {
							dp[k][i][j] = dp[k - 1][A][B] + c[i][j];
							fr[k][i][j] = A * 26 + B;
						}
			}
	}

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++) if (i != j)
			if (!v || dp[n - 1][v / 26][v % 26] > dp[n - 1][i][j])
				v = i * 26 + j;
	printf("%d\n", dp[n - 1][v / 26][v % 26] );
	out(n - 1, v);
	return 0;
}


// special case: m = 1




// lang: GNU C++
// memory: 4300 KB
// author: imslavko
// submit_date: Jul 9, 2011 6:54:31 PM
// contest: 18
// link: /contest/18/submission/539625
// time: 550 ms
// verdict: Accepted
// problem: 18E - Flag 2
// ID: 539625
// downloaded by very stupid script
