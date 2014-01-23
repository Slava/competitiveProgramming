#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


const int MAXN = 50100;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow;
};
int n, m, s, t, d[MAXN], ptr[MAXN], q[MAXN], E;

edge e[MAXN*3*4];
vector<int> g[MAXN];
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back (E);
	e[E++] =  e1;
	g[b].push_back (E);
	e[E++] = e2;;
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (int i = 0; i < (int)g[v].size(); i++) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow) return 0;
	if (v == t) return flow;
	for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1) continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

long long dinic() {
	long long flow = 0;
	for (;;) {
		if (!bfs()) break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int main() {
	freopen("prune.in", "r", stdin);
	freopen("prune.out", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &s, &t);
	s--; t--;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		x--; y--;
		add_edge(x, y, w);
		add_edge(y, x, w);
	}

#ifdef WIN
	printf("%I64d\n", dinic());
#else
	printf("%lld\n", dinic());
#endif

	return 0;
}


