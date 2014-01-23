#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>


#define N 201000
int link[2*N][26], len[2*N], suff[2*N], last, sz = 1;
bool cln[2*N], u[2*N];
int dp[2*N];
std::vector<int> g[2*N];

void init() {
	memset(link, -1, sizeof link);
	memset(suff, -1, sizeof suff);
}

void addChar(int c) {
	int newl = sz++;
	len[newl] = len[last] + 1;
	
	int v = last;
	for (; v != -1 && link[v][c] == -1; v = suff[v])
		link[v][c] = newl;
	if (v == -1)
		suff[newl] = 0;
	else {
		int u = link[v][c];
		if (len[v] + 1 == len[u])
			suff[newl] = u;
		else {
			int cl = sz++;
			len[cl] = len[v] + 1;
			suff[cl] = suff[u];
			for (int i = 0; i < 26; i++)
				link[cl][i] = link[u][i];
			cln[cl] = 1;
			for (; v != -1 && link[v][c] == u; v = suff[v])
				link[v][c] = cl;
			suff[u] = suff[newl] = cl;
		}
	}

	last = newl;
}

int go(int v) {
	if (u[v])  return dp[v];
	int &res = dp[v];
	u[v] = 1;
	res = !cln[v];	
	for (int i = 0; i < (int)g[v].size(); i++)
		res += go(g[v][i]);
	return res;
}

int l, ans;
char s[N];
int main() {
	init();
	scanf("%d%s", &l, s);
	for (int i = 0; i < l; i++) {
		addChar(s[i]-'a');
	}

	for (int i = 1; i < sz; i++)
		g[suff[i]].push_back(i);

	for (int i = 1; i < sz; i++)
		if (go(i) > 1 && ans < len[i])
			ans = len[i];

	printf("%d\n", ans);

	return 0;
}



