#include <cstdio>
#include <cstdlib>
#include <cstring>

const int M = 3;
char S[M * 10];
struct bigint {
	int a[M];
	bigint() { memset(a, 0, sizeof a); }
	void operator += (bigint b) {
		int c = 0;
		for (int i = 0; i < M; i++) {
			a[i] += b.a[i] + c;
			c = a[i] / int(1e9);
			a[i] %= int(1e9);
		}
	}

	bigint operator * (bigint b) {
		bigint c; long long t, carry = 0;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++) {
				if (i + j >= M) continue;
				t = a[i]; t *= b.a[j];
				t += c.a[i + j] + carry;
				c.a[i + j] = int(t % int(1e9));
				carry = t / int(1e9);
			}
		return c;
	}

	void out() {
		int l = 0;
		for (int i = M - 1; i >= 0; i--)
			l += sprintf(S + l, "%09d", a[i]);
		l = 0;
		while (S[l] == '0')
			l++;
		if (S[l])printf("%s\n", S + l);
		else printf("0\n");
	}
};

const int N = 51;
char s[N], t[N];
int n, kn[N][N][N];

bigint dp[N][N][N];
void get(int sr, int si, int len) {
	bigint& res = dp[sr][si][len];
	if (!len)
		res.a[0] = kn[sr][si][len] = 1;
	if (kn[sr][si][len]) return;
	kn[sr][si][len] = 1;
	for (int i = 0; i < len; i++)
		if (s[sr] == t[si + i]) {
			get(sr + 1, si, i);
   			get(sr + i + 1, si + i + 1, len - 1 - i);
			res += dp[sr + 1][si][i] * 
				dp[sr + i + 1][si + i + 1][len - i - 1];
		}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%s%s", s, t);
	n = strlen(s);

	get(0,0,n);
	dp[0][0][n].out();

	return 0;
}
