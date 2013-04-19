#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

typedef long long Int;
struct edge {
	int y, w, l;
}t;
vector<edge>g[10101];
Int dp[10101][2];
int n, m, x, L = 1, C = 3, P = 0;
char l[50];

Int go(int v, int l) {
	if (dp[v][l] != -1)
		return dp[v][l];
	if (v == n)
		return 0;
	dp[v][l] = -2;
	Int mn = (1ll << 62);
	for (vector<edge>::iterator i = g[v].begin();
		i != g[v].end(); i++) {
		if (i->l == L && l != L)
			continue;
		Int Get = go(i->y, l & i->l);
		if (mn > Get + i->w && Get != -2)
			mn = Get + i->w;
	}
	if (mn != (1ll << 62))
		dp[v][l] = mn;
	return dp[v][l];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%s", &x, &t.y, &t.w, l);
		if (l[0] == 'L')
			t.l = L;
		else if (l[0] == 'C')
			t.l = C;
		else t.l = P;
		g[x].push_back(t);
	}
	memset(dp, -1, sizeof dp);
	if(go(1, L) != -2)
		printf("Online\n" i64 "\n", go(1, L));
	else printf("Offline\n");
	return 0;
}
