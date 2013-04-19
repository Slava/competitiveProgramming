#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bitset>

#include <cmath>
#include <cstring>

using namespace std; 


struct Edge {
	int x, y, cost;
	Edge(int X, int Y, int Cost) { x = X; y = Y; cost = Cost; }
	bool operator < (const Edge b) const {
		return cost != b.cost ? cost < b.cost : (x < b.x || (x == b.x && y < b.y));
	}
};

struct DSU {
	vector<int> p, r;
	DSU(int size) {
		r.assign(size, 1);
		p.resize(size);
		for (int i = 0; i < size; i++)
			p[i] = i;
	}
	DSU() {}

	int get(int x) { return p[x] == x ? x : (p[x] = get(p[x])); }
	bool unite(int x, int y) {
		x = get(x); y = get(y);
		if (x == y)
			return false;
		if (r[x] < r[y])
			swap(x,y);
		p[y] = x;
		r[x] += r[y];
		return true;
	}
};

vector<pair<Edge,int> > edges;
vector<string> answer;
DSU dsu;
vector<vector<int> > g;
vector<int> u, d, l;
int n, m, globalCounter;

void dfs(int v, int p = -1, int depth = 0) {
	l[v] = d[v] = depth;
	u[v] = globalCounter+1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		if (g[v][i] == p)continue;
		int id = g[v][i], x = dsu.get(edges[id].first.x), y = dsu.get(edges[id].first.y), to = x == v ? y : x;
		if (u[to]>globalCounter)
			l[v] = min(l[v], d[to]);
		else {
			dfs(to, g[v][i], depth+1);
			l[v] = min(l[v], l[to]);
		}

		if (l[to] > d[v]) {
			answer[edges[g[v][i]].second] = "any";
		}
	}
}

void solve() {
//	cin >> n >> m;
	scanf("%d%d", &n, &m);
	d.resize(n); l.resize(n); u.resize(n);
	g.assign(n, vector<int> ());
	answer.assign(m, "at least one");

	dsu = DSU(n);
	for (int i = 0; i < m; i++) {
		int x, y, z;
//		cin >> x >> y >> z;
		scanf("%d%d%d", &x, &y, &z);
		x--; y--;
		edges.push_back(make_pair(Edge(x,y,z),i));
	}

	sort(edges.begin(), edges.end());
	for (int i = 0; i < m;) {
		int k = i;
		while (k < (int)edges.size() && edges[k].first.cost == edges[i].first.cost)
			k++;
		for (int j = i; j < k; j++) {
			int x, y;
			x = dsu.get(edges[j].first.x);
			y = dsu.get(edges[j].first.y);

			if (x != y) {
				g[x].push_back(j);
				g[y].push_back(j);
			} else
				answer[edges[j].second] = "none";
		}

		for (int j = i; j < k; j++) {
			int x, y;
			x = dsu.get(edges[j].first.x);
			y = dsu.get(edges[j].first.y);
			if (u[x]<=globalCounter)
				dfs(x);
			if (u[y]<=globalCounter)
				dfs(y);
		}
		for (int j = i; j < k; j++) {
			int x, y;
			x = dsu.get(edges[j].first.x);
			y = dsu.get(edges[j].first.y);
			dsu.unite(x, y);
			g[x].clear(); g[y].clear();
		}

		i = k;
		globalCounter++;
	}
	for (int i = 0; i < m; i++)
//		cout << answer[i] << "\n";
		puts(answer[i].c_str());
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 16100 KB
// author: imslavko
// submit_date: Mar 9, 2012 4:01:52 PM
// contest: 160
// link: /contest/160/submission/1320843
// time: 300 ms
// verdict: Accepted
// problem: 160D - Edges in MST
// ID: 1320843
// downloaded by very stupid script
