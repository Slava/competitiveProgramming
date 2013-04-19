#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>


const int N = 200100, K = 26;

int last, sz;
int len[N], suff[N];
int link[N][K];
bool terminate[N], clonned[N];
std::vector<int>g[N];

int conv(char c) {
	return c - 'a';
}

void init() {
	sz = 1;
	memset(link[0], -1, sizeof link[0]);
	memset(terminate, 0, sizeof terminate);
	memset(clonned, 0, sizeof clonned);
	len[0] = 0; suff[0] = -1; last = 0;
}

void add_char(int c) {
	int newv = sz++, v;
	memset(link[newv], -1, sizeof link[newv]);
	len[newv] = len[last] + 1;

	for (v = last; v != -1; v = suff[v])
		if (link[v][c] == -1)
			link[v][c] = newv;
		else break;
// 1
	if (v == -1)
		suff[newv] = 0;
	else {
		int u = link[v][c];
		// 2.a
		if (len[v] + 1 == len[u])
			suff[newv] = u;
		else {
			// 2.b
			int clone = sz++;
			len[clone] = len[v] + 1;
			memcpy(link[clone], link[u], sizeof link[u]);
			suff[clone] = suff[u];
			clonned[clone] = 1;

			for (; v != -1 && link[v][c] == u; v = suff[v])
				link[v][c] = clone;

			suff[newv] = suff[u] = clone;
		}
	}
	last = newv;
}

#define int long long
int dp[N],dp2[N];
bool u[N];

int go(int v) {
	if (u[v])return dp[v];
	u[v] = 1;
	dp[v] = !clonned[v];
	for (int i = 0; i < (int)g[v].size(); i++)
		dp[v] += go(g[v][i]);
	return dp[v];
}

int go2(int v) {
	if (u[v]) return dp2[v];
	u[v] = 1;
	dp2[v] = dp[v];
	for (int i = 0; i < 26; i++)
		dp2[v] += go2(link[v][i]);
	return dp2[v];
}

char s[N];
int n, k;
main() {
	scanf("%s", s);
#ifdef WIN32
	scanf("%I64d", &k);
#else
	scanf("%lld", &k);
#endif

	n = strlen(s);
	init();
	for (int i = 0; i < n; i++)
		add_char(s[i] - 'a');
	for (int i = 1; i < sz; i++)
		g[suff[i]].push_back(i);

	for (int i = 1; i < sz; i++)
		go(i);

	memset(u, 0, sizeof u);
	for (int i = 0; i < sz; i++) {
		go2(i);
//		printf("%d\n", go2(i));
	}

	if (k > go2(0)) {
		puts("No such line.");
		return 0;
	}

	int v = 0;
	for(;;) {
		k -= go(v);
		if (k <= 0)
			break;
		for (int i = 0; i < 26; i++)
			if (link[v][i] != -1) {
				int to = link[v][i];
				if (k > go2(to))
					k -= go2(to);
				else {
					printf("%c", 'a' + i);
					v = to;
					break;
				}
			}
	}
	puts("");

}






// lang: GNU C++
// memory: 37400 KB
// author: imslavko
// submit_date: Nov 15, 2011 1:34:58 PM
// contest: 128
// link: /contest/128/submission/870869
// time: 130 ms
// verdict: Accepted
// problem: 128B - String
// ID: 870869
// downloaded by very stupid script
