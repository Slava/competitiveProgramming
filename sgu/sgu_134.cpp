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

const int N = 16100;

int n, size[N], wCentroid = (int)1e9, w[N];
vector<int> g[N];

void dfs(int v, int p = -1) {
	size[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (to == p)
			continue;
		dfs(to, v);
		size[v] += size[to];
		w[v] = max(w[v], size[to]);
	}

	w[v] = max(w[v], n-size[v]);
	wCentroid = min(wCentroid, w[v]);
}

int main() {
	scanf("%d", &n);
	
	for (int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0);

	int answer = 0;
	for (int i = 0; i < n; i++)
		if (w[i] == wCentroid)
			answer++;

	printf("%d %d\n", wCentroid, answer);
	for (int i = 0; i < n; i++)
		if (wCentroid == w[i])
			printf("%d ", i+1);
	puts("");
	
	return 0;
}
