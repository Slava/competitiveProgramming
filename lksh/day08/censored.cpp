#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

const int base = 1000000000;
const int Sigma = 100, NODES = 2000;

struct bigint {
    vector<int> a;
	bigint operator+(const bigint &v) const {
		bigint res = v;
		for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
			if (i == (int) res.a.size())
				res.a.push_back(0);
			res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
			carry = res.a[i] >= base;
			if (carry)
				res.a[i] -= base;
		}
		return res;
	}
}dp[NODES][2], ans;

struct node{
	int next[Sigma], go[Sigma], fail, p;
	int pch, leaf;
	node (){
		leaf = 0; p = fail = 0;
		memset(next, 0, sizeof next);
		memset(go, 0, sizeof go);
	}
}bor[NODES];
char s[150];
int len, m, n, p, q[NODES], h, t, root = 1, M = 2, u[NODES];
map<char,int>Map;

void add_string (char *str, int sz){
	int v = root;
	for (; sz--; str++){
		int l = Map[*str];
		if (!bor[v].next[l]){
			bor[v].next[l] = M++;
			bor[bor[v].next[l]].p = v;
			bor[bor[v].next[l]].pch = l;
		}
		v = bor[v].next[l];
	}
	bor[v].leaf = 1;
}

int go (int v, int ch);
int get_link (int v){
	if (!bor[v].fail)
		if (v == root || bor[v].p == root)
			bor[v].fail = root;
		else bor[v].fail = go(get_link(bor[v].p), bor[v].pch);
	return bor[v].fail;
}

int go (int v, int ch){
	if (!bor[v].go[ch])
		if (!bor[v].next[ch])
			bor[v].go[ch] = v == root ? root : go(get_link(v), ch);
		else bor[v].go[ch] = bor[v].next[ch];
	return bor[v].go[ch];
}

int main (){
	scanf("%d%d%d", &m, &n, &p);gets(s);
	gets(s);
	for (int i = 0; i < m; i++)
		Map[s[i]] = i;
	for (int i = 0; i < p; i++){
		gets(s);
		add_string(s, len = strlen(s));
	}
	for (int i = 1; i < M; i++) {
		int v = i;
		while (v != root && !bor[i].leaf) {
			v = get_link(v);
			if (bor[v].leaf)
				bor[i].leaf = 1;
		}
	}
	dp[root][0].a.push_back(1);
	for (int i = 0; i <= n; i++) {
		h = t = 0; q[t++] = root;
		memset(u, 0, sizeof u); u[root] = 1;
		int cur = i & 1, nxt = cur ^ 1;
		for (int j = 0; j < M; j++)
			dp[j][nxt].a.clear();
		while (h < t) {
			int v = q[h++];
			if (i == n)ans = ans + dp[v][cur];
			for (int j = 0; j < m; j++) {
				int to = go(v, j);
				if (!u[to]) {
					q[t++] = to;
					u[to] = 1;
				}
				if (!bor[to].leaf)
					dp[to][nxt] = dp[to][nxt] + dp[v][cur];
			}
		}
	}
	if (ans.a.empty())printf("0");
	else printf("%d", ans.a.back());
	for (int i = (int)ans.a.size() - 2; i >= 0; i--)
		printf("%09d", ans.a[i]);
	printf("\n");
	return 0;
}

