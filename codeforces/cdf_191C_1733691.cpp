#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std; 

#define pb push_back

const int N = 1<<17;

bool u[N];
int n, m;
int lvl[N], add[N], ea[N], eb[N], sgt[N*4], first[N*2];
vector<int> g[N], ls;

void dfsDP(int v) {
	u[v] = true;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (!u[to]) {
			dfsDP(to);
			add[v] += add[to];
		}
	}
}

void dfs(int v) {
	u[v] = true;
	ls.pb(v);
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (!u[to]) {
			lvl[to] = lvl[v] + 1;
			dfs(to);
			ls.pb(v);
		}
	}
}

void buildSgt() {
	int n = (int)ls.size();
	for (int i = 0; i < n; i++)
		sgt[i+n] = ls[i];
	for (int i = n-1; i > 0; i--)
		if (lvl[sgt[i+i]] < lvl[sgt[i+i+1]])
			sgt[i] = sgt[i+i];
		else 
			sgt[i] = sgt[i+i+1];
}

int getMin(int l, int r) {
	int n = (int)ls.size(), ind = 0;
	l += n; r += n;
	if (l > r) swap(l, r);
	while (l <= r) {
		if (l&1)
			if (lvl[ind] > lvl[sgt[l]])
				ind = sgt[l];
		if (!(r&1))
			if (lvl[ind] > lvl[sgt[r]])
				ind = sgt[r];
		l = (l+1)/2;
		r = (r-1)/2;
	}
	assert(ind);
	return ind;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> ea[i] >> eb[i];
		g[ea[i]].pb(eb[i]);
		g[eb[i]].pb(ea[i]);
	}
	
	lvl[0] = 1<<30;
	dfs(1);
	buildSgt();
	for (int i = (int)ls.size(); i >= 0; i--)
		first[ls[i]] = i;

	cin >> m;
	while (m--) {
		int x, y, lca;
		cin >> x >> y;
		lca = getMin(first[x], first[y]);
		add[x]++; add[y]++;
		add[lca] -= 2;
	}

	memset(u, 0, sizeof u);
	dfsDP(1);
	
	for (int i = 0; i < n - 1; i++) {
		int x = ea[i], y = eb[i];
		if (lvl[x] < lvl[y])
			x = y;
		cout << add[x] << " ";
	}
	cout << endl;

	return 0;
}




// lang: GNU C++
// memory: 15100 KB
// author: imslavko
// submit_date: May 28, 2012 11:45:47 AM
// contest: 191
// link: /contest/191/submission/1733691
// time: 530 ms
// verdict: Accepted
// problem: 191C - Fools and Roads
// ID: 1733691
// downloaded by very stupid script
