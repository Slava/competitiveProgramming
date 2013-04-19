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

using namespace std; 

#define pb push_back

const int N = 3000;

struct Edge {
	int x, y, cost;
	int f, c;
} a[N*200];

struct Task {
	int s, t, c;
} task[N];

int n, m, inf = (int)1e9, nn, k;
int d[N], u[N], phi[N], from[N], answer[N], times[N];
vector<int> g[N];

void add_edge (int x, int y, int z, int c) {
	a[m].x = x; a[m].y = y; a[m].cost = z; a[m].c = c; a[m].f = 0; m++;
	g[x].pb(m - 1);
	a[m].x = y; a[m].y = x; a[m].cost = -z; a[m].c = 0; a[m].f = 0; m++;
	g[y].pb(m - 1);
}

bool dijkstra (int s, int t) {
	for (int i = 0; i < n; i++) {
		u[i] = 0; d[i] = inf; from[i] = -1;
	}

	d[s] = 0;
	while (true) {
		int v = -1;
		for (int i = 0; i < n; i++) 
			if (!u[i] && (v == -1 || d[v] > d[i]))
				v = i;
		if (v == -1 || d[v] == inf)
			break;
		u[v] = 1;
		for (int i = 0; i < (int)g[v].size(); i++) {
			int to = g[v][i];
			int x = v, y = a[to].y, z = a[to].cost,
				f = a[to].f, c = a[to].c;
			if (c - f <= 0)
				continue;
			if (d[y] > d[x] + phi[x] - phi[y] + z) {
				d[y] = d[x] + phi[x] - phi[y] + z;
				from[y] = to;
			}
		}
	}
	return d[t] < inf;
}

void fordbellman(int s) {
	for (int i = 0; i < n; i++)
		phi[i] = inf;
	phi[s] = 0;

	for (int k = 0; k < n; k++)
		for (int i = 0; i < m; i++)
			if (phi[a[i].y] > phi[a[i].x] + a[i].cost && a[i].c > 0) {
				phi[a[i].y] = phi[a[i].x] + a[i].cost;
			}
}

int mincost_maxflow (int s, int t) {
	int flow, cost;
	flow = cost = 0;

	fordbellman(s);
	while (true) {
		if (!dijkstra(s, t))
			break;
		for (int i = 0; i < n; i++)
			phi[i] += d[i];
		int v = t, mx = inf, u, k;
		for (;v != s; v = u) {
			k = from[v];
			u = a[k].x;
			mx = min(mx, a[k].c - a[k].f);
		}

		for (v = t; v != s; v = u) {
			k = from[v];
			u = a[k].x;
			cost += a[k].cost * mx;
			a[k].f += mx;
			a[k^1].f -= mx;
		}
		flow += mx;
	}

	return cost;
}

int main() {
	cin >> nn >> k;
	n = nn*2+2;

	for (int i = 0; i < nn; i++) {
		cin >> task[i].s >> task[i].t >> task[i].c;
		times[i*2] = task[i].s;
		times[i*2+1] = task[i].s + task[i].t;
	}

	sort(times,times+nn+nn);
	n = unique(times,times+nn+nn) - times;

	int s = n+1, t = n;
	for (int i = 0; i < n; i++)
		add_edge(i, i+1, 0, k);
	add_edge(s, 0, 0, k);

	for (int i = 0; i < nn; i++) {
		int f = lower_bound(times, times+n, task[i].s) - times;
		int t = lower_bound(times, times+n, task[i].s + task[i].t) - times;
		add_edge(f, t, -task[i].c, 1);
	}

	n += 2;
	mincost_maxflow(s, t);

	for (int i = 0; i < m; i += 2)
		if (a[i].cost < 0)
			cout << (a[i].f > 0 ? "1" : "0") << " ";

	return 0;
}





// lang: GNU C++
// memory: 13300 KB
// author: imslavko
// submit_date: Apr 9, 2012 6:19:18 PM
// contest: 164
// link: /contest/164/submission/1507117
// time: 310 ms
// verdict: Accepted
// problem: 164C - Machine Programming
// ID: 1507117
// downloaded by very stupid script
