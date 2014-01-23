#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

using namespace std; 

const int N = 100100;
vector<int> g[N], bg[N], ls, ans, id[N];
vector<long long>w[N];
int n, u[N], m, comp;
long long sum, d[N];
int from[N], num[N];
bool in[N], out[N];
set<pair<long long,int> >Set;
#define mp make_pair
void dfs(int v) {
	u[v] = 1;
	int to;
	for (int i = 0; i < (int)g[v].size(); i++)
		if (!u[to = g[v][i]])
			dfs(to);
	ls.push_back(v);
}

void col(int v, int c) {
	u[v] = c;
	int to;
	for (int i = 0; i < (int)bg[v].size(); i++)
		if (!u[to = bg[v][i]])
			col(to, c);
}

#define BIGCONST 10000000000LL

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

void findStrong() {
	comp = 0;
	ls.clear();
	memset(u, 0, sizeof u);
	for (int i = 0; i < n; i++)
		if (!u[i])
			dfs(i);

	memset(u, 0, sizeof u);
	for (int i = (int)ls.size() - 1; i >= 0; i--)
		if (!u[ls[i]]) {
			col(ls[i], ++comp);
		}
}

int main() {
	freopen("aug.in", "r", stdin);
	freopen("aug.out", "w", stdout);

	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].push_back(y);
		w[x].push_back(0);
		id[x].push_back(0);
		bg[y].push_back(x);
	}

	findStrong();
	int to, s, t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)g[i].size(); j++)
			if (u[i] != u[to = g[i][j]]) {
//				printf("edge %d->%d\n", i,to);
				in[u[to]] = out[u[i]] = 1;
			}

	for (int i = 0; i < n; i++) {
		if (!in[u[i]])
			s = i;
		if (!out[u[i]])
			t = i;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y, ww;
		scanf("%d%d%d", &x, &y, &ww);
		x--; y--;
		g[x].push_back(y);
		w[x].push_back(ww+BIGCONST);
		id[x].push_back(i+1);
	}

	for (int i = 0; i < n; i++)
		d[i] = 1LL << 60;
	d[t] = 0;

	Set.insert(mp(0,t));
	while (!Set.empty()) {
		int v = Set.begin()->second;
		Set.erase(Set.begin());
		for (int i = 0; i < (int)g[v].size(); i++)
			if (d[to = g[v][i]] > d[v] + w[v][i]) {
				Set.erase(mp(d[to],to));
				d[to] = d[v] + w[v][i];
				from[to] = v;
				num[to] = i;
				Set.insert(mp(d[to],to));
			}
	}

	if (d[s] == (1LL<<60)) {
		puts("NO");
		return 0;
	}

	int v = s;
	while (v != t) {
		if (w[from[v]][num[v]]) {
			ans.push_back(id[from[v]][num[v]]);
			sum += w[from[v]][num[v]] - BIGCONST;
		}
		v = from[v];
	}

	puts("YES");
	printf(i64 "\n%d\n", sum, (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");

	return 0;
}
