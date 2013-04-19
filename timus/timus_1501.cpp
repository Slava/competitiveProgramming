#include <cstdio>
#include <cstdlib>
#include <cstring>
#define abs(x) (x<0?-(x):x)

int n, fr[1010][1010], sum1, sum2;
char s[2][1010];

inline int get(int n, int m, int s1, int s2) {
	if (fr[n][m] != -1)return fr[n][m];
	if (abs(s1 - s2) > 1) return fr[n][m] = 0;
	fr[n][m] = 0;
	if (n) {
		if(get(n - 1, m, s1 - (s[0][n - 1] == '0'), s2 - (s[0][n - 1] == '1')))
			fr[n][m] = 1;
	}
	if (m && !fr[n][m]) {
		if(get(n, m - 1, s1 - (s[1][m - 1] == '0'), s2 - (s[1][m - 1] == '1')))
			fr[n][m] = 2;
	}
	return fr[n][m];
}	

inline void out(int n, int m) {
	if (!n && !m)return;
	fr[n][m] == 1 ? out(n - 1, m) : out(n, m - 1);
	printf("%d", fr[n][m]);
}

int main (){
	scanf("%d", &n);
	scanf("%s%s", s[0], s[1]);
	memset(fr, ~0, sizeof fr);
	for (int i = 0; i < n; i++) {
		sum1 += (s[0][i] == '0') + (s[1][i] == '0');
		sum2 += (s[0][i] == '1') + (s[1][i] == '1');
	}
	fr[0][0] = -2;
	if (get(n, n, sum1, sum2)) {
		out(n, n);
	}
	else puts("Impossible");
	return 0;
}


