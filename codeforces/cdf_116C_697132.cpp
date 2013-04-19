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

const int N = 3000;
vector<int> g[N];
int n, u[N], ans;

int dfs(int v) {
	u[v] = 1;
	int mx = 0;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		mx = max(mx, dfs(to));
	}
	return mx + 1;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		if (p != -1)
			g[p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (!u[i])
			ans = max(ans, dfs(i));
	cout << ans << endl;
	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Sep 15, 2011 7:14:40 PM
// contest: 116
// link: /contest/116/submission/697132
// time: 50 ms
// verdict: Accepted
// problem: 116C - Party
// ID: 697132
// downloaded by very stupid script
