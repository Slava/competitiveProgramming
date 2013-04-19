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

#define abs(x) (x<0?-(x):x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0);
	if (fopen("graphon.in", "r")) {
		freopen("graphon.in", "r", stdin);
		freopen("graphon.out", "w", stdout);
	}

	int n, m;
	while (cin >> n >> m) {
		if (!n && !m)
			break;
		vector<vector<pair<int,int> > > g;
		g.resize(n);

		for (int i = 0; i < m; i++) {
			int x, y, l;
			cin >> x >> y >> l;
			x -= 100; y -= 100;
			g[x].pb(mp(y,l));
			g[y].pb(mp(x,l));
		}

		vector<int> d(n, 1<<29), u(n, 0);
		int s = n-1, t = 0;
		d[s] = 0;

		while (true) {
			int v = -1;
			for (int i = 0; i < n; i++)
				if (!u[i] && (v==-1 || d[v] > d[i]))
					v = i;

			if (v == -1)
				break;
			u[v] = 1;
			for (int i = 0; i < (int)g[v].size(); i++) {
				int to = g[v][i].f, len = g[v][i].s;
				if (d[to] > d[v] + len)
					d[to] = d[v] + len;
			}
		}

		while (t != s) {
			cout << t + 100 << " ";
			int tt = 100500;
			for (int i = 0; i < (int)g[t].size(); i++) {
				int to = g[t][i].f, len = g[t][i].s;
				if (d[to] == d[t]-len && tt > to)
					tt = to;
			}
			t = tt;
		}
		cout << s + 100 << "\n";
	}
	return 0;
}
