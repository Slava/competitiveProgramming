#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std; 

#define pb push_back

const int N = 410;
int n, m, inf = (int)1e9;
vector<int> G[N];
int w[N][N];
int from[N];
bool u[N];

struct Edge {
	Edge(int a, int b, int c) 
		: a(a), b(b), c(c), f(0) {}
	Edge() {}
	short a, b, c, f;
};
Edge edges[80010];
int ee;

void addEdge(int a, int b, int c) {
	Edge t(a,b,c);
	G[a].pb(ee);
	edges[ee++] = t;
	t = Edge(b,a,0);
	G[b].pb(ee);
	edges[ee++] = t;
}

void dfs(int v) {
	printf("%d ", v+1);
	if (v == n-1)
		return;
	for (int i = 0; i < (int)G[v].size(); i++)
		if (edges[G[v][i]].f > 0) {
			edges[G[v][i]].f--;
			dfs(edges[G[v][i]].b);
			return;
		}
}

bool bfs() {
	fill(from,from+n,-1);
	
	queue<int> q;
	q.push(0);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < (int)G[v].size(); i++) {
			int e = G[v][i], to = edges[e].b;
			if (edges[e].c-edges[e].f <= 0)
				continue;
			if (from[to] == -1) {
				from[to] = e;
				q.push(to);
			}
		}
	}

	return from[n-1] != -1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		w[a][b] = w[b][a] = c;
	}

	fill(from,from+n,inf);
	from[0] = 0;
	
	for (int k = 0; k < n; k++) {
		int v = -1;
		for (int i = 0; i < n; i++)
			if (!u[i] && (v == -1 || from[v] > from[i]))
				v = i;
		u[v] = 1;
		for (int i = 0; i < n; i++) {
			if (!w[v][i])continue;
			int to = i;
			if (from[to] > from[v] + w[v][i])
				from[to] = from[v] + w[v][i];
		}
	}

	for (int v = 0; v < n; v++)
		for (int to = 0; to < n; to++) if(w[v][to])
			if (from[v] + w[v][to] == from[to])
				addEdge(v, to, 1);

	int flow = 0;
	for (int k = 2; k > 0 && bfs(); k--) {
		flow++;
		int v = n-1;
		while(v != 0) {
			int e = from[v];
			edges[e].f++;
			edges[e^1].f--;

			v = edges[e].a;
		}
	}

	if (flow != 2) {
		puts("No solution");
	} else {
		dfs(0); puts("");
		dfs(0); puts("");
	}


	return 0;
}
