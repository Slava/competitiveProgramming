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
#define pb push_back
#define mp make_pair

const int N = 210100;

int n, root, answerRoot, d[N], minAns = 1<<30;
vector<pair<int,int> > g[N];

void dfs(int v, int p = -1) {
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i].first, w = g[v][i].second;
		if (to == p)
			continue;
		answerRoot += w;
		if (w)
			d[to] = d[v]-1;
		else
			d[to] = d[v]+1;
		dfs(to,v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(mp(b,0));
		g[b].pb(mp(a,1));
	}

	dfs(root);
	for (int i = 0; i < n; i++)
		minAns = min(minAns, answerRoot+d[i]);
	cout << minAns << "\n";

	for (int i = 0; i < n; i++)
		if (minAns == answerRoot+d[i])
			cout << i+1 << " ";
	cout << "\n";

	return 0;
}
