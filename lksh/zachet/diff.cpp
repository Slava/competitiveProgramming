#include <cstdio>
#include <cstdlib>
#include <cstring>

const int SIGMA = 26, N = 101010;
typedef long long Int;
struct node {
	int len, suff, go[SIGMA];
	node() {
		len = suff = 0;
		memset(go, -1, sizeof go);
	}
} st[N*2];
int M = 1, last;

void add_char(int C) {
	int newl = M++, v = last;
	st[newl].len = st[last].len + 1;
	for (; v != -1 && st[v].go[C] == -1; v = st[v].suff)
		st[v].go[C] = newl;
	if (v == -1)
		st[newl].suff = 0;
	else {
		int q = st[v].go[C];
		if (st[v].len + 1 == st[q].len)
			st[newl].suff = q;
		else {
			int clone = M++;
			st[clone] = st[q];
			st[clone].len = st[v].len + 1;
			for (; v != -1 && st[v].go[C] == q; v = st[v].suff)
				st[v].go[C] = clone;
			st[newl].suff = st[q].suff = clone;
		}
	}
	last = newl;
}

char s[N];
int n, u[N*2], q[N*2], h, t;
Int dp[N*2], d[N*2], ans;
bool was[N*2];

void cnt(int v) {
	if (was[v])return;
	was[v] = 1;
	for (int i = 0; i < SIGMA; i++) {
		int q = st[v].go[i];
		if (q == -1)continue;
		cnt(q);
		d[v] += d[q] + 1;
		dp[v] += d[q] + dp[q] + 1;
	}
}

int main() {
	st[0].suff = -1;
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		add_char(s[i] - 'a');
	cnt(0); ans = dp[0];
	printf("%lld\n", ans);
	return 0;
}
