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

const int N = 1010;
typedef pair<int,int> ii;
vector<ii> g[N];
vector<pair<ii,int> >ans;
int in[N], out[N];
int n, m;

void process(int v) {
	int D = 1<<30, start = v;
	while (!g[v].empty()) {
		D = min(D, g[v][0].second);
		v = g[v][0].first;
	}

	if (start != v)
		ans.push_back(make_pair(ii(start,v),D));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		g[a].push_back(ii(b,d));
		in[b]++; out[a]++;
	}

	for (int i = 1; i <= n; i++)
		if (!in[i])
			process(i);
	sort (ans.begin(), ans.end());

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 1, 2012 10:35:10 AM
// contest: 108
// link: /contest/108/submission/1129812
// time: 30 ms
// verdict: Accepted
// problem: 108C - Dorm Water Supply
// ID: 1129812
// downloaded by very stupid script
