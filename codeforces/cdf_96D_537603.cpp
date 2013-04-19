#include <cstdio>
#include <set>
#include <iostream>

using namespace std;

typedef long long Int;
typedef pair<Int, int> ii;
const int N = 1500;
int n, m, he[N], ne[N * 2], no[N * 2], M = 1;
int s, f, u[N];
Int g[N][N], w[N * 2], t[N], c[N], ds[N];
set<ii>h;


void add(int x, int y, Int W) {
	no[M] = y; w[M] = W; ne[M] = he[x]; he[x] = M++;
}

void dijkstra(int s) {
	Int *d; d = g[s];
	for (int i = 1; i <= n; i++)
		d[i] = (1ll << 60);
	d[s] = 0;
	h.insert(ii(0,s));
	while(!h.empty()){
		int v = h.begin()->second;
		h.erase(h.begin());
		for (int i = he[v]; i; i = ne[i]) {
			int to = no[i]; Int D = w[i];
			if (d[to] > d[v] + D) {
				h.erase(ii(d[to], to));
				d[to] = d[v] + D;
				h.insert(ii(d[to], to));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> s >> f;
	for (int i = 0; i < m; i++) {
		int x, y; Int w;
		cin >> x >> y >> w;
		add(x, y, w); add(y, x, w);
	}
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		ds[i] = (1ll << 60);
	}
	ds[s] = 0;
	for (int k = 1; k <= n; k++) {
		int v = -1;
		for (int i = 1; i <= n; i++)
			if (!u[i] && (v == -1 || ds[v] > ds[i]))
				v = i;
		u[v] = 1;
		for (int i = 1; i <= n; i++)
			if (g[v][i] <= t[v] && ds[i] > ds[v] + c[v])
				ds[i] = ds[v] + c[v];
	}
	if (ds[f] >= (1ll << 60))
		ds[f] = -1;
	cout << ds[f];
	return 0;
}





// lang: GNU C++
// memory: 19100 KB
// author: imslavko
// submit_date: Jul 8, 2011 10:28:58 PM
// contest: 96
// link: /contest/96/submission/537603
// time: 500 ms
// verdict: Accepted
// problem: 96D - Volleyball
// ID: 537603
// downloaded by very stupid script
