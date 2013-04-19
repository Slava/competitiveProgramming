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

const int N = 101010;
int n, m, type[N], u[N], uu[N];
vector<int> g[N], b[N];

void dfs(int v) {
	if (u[v])return;
	u[v] = 1;

	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		dfs(to);
	}
}

void Dfs(int v) {
	if (uu[v])return;
	uu[v] = 1;
	if (type[v] == 1)
		return;

	for (int i = 0; i < (int)b[v].size(); i++) {
		int to = b[v][i];
		Dfs(to);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> type[i];
	}

	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		if (l == r)continue;
		g[l].push_back(r);
		b[r].push_back(l);
	}

	for (int i = 0; i < n; i++)
		if (type[i] == 1) {
			dfs(i);
		}
	for (int i = 0; i < n; i++)
		if (type[i] == 2) {
			Dfs(i);
		}

	for (int i = 0; i < n; i++) {
		cout << (u[i]&uu[i]) << "\n";
	}


	return 0;
}




// lang: GNU C++
// memory: 11200 KB
// author: imslavko
// submit_date: Apr 8, 2012 8:11:36 PM
// contest: 164
// link: /contest/164/submission/1501476
// time: 450 ms
// verdict: Accepted
// problem: 164A - Variable, or There and Back Again
// ID: 1501476
// downloaded by very stupid script
