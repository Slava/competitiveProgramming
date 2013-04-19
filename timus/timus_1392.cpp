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

#define sq(x) (x)*(x)

int n, r[1010], x[1010], y[1010], z[1010],
	a[1010][1010], u[1010], c;
vector<int> V;

bool in(int i, int j) {
	return sq(r[i] + r[j]) > sq(x[i] - x[j]) + sq(y[i] - y[j]) + sq(z[i] - z[j]);
}

void dfs(int v) {
	u[v] = 1;
	V.push_back(v);
	for (int i = 0; i < n; i++)
		if (a[v][i] && !u[i])
			dfs(i);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", x + i, y + i, z + i, r + i);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			a[i][j] = a[j][i] = in(i, j);
	for (int i = 0; i < n; i++)
		if (!u[i]) {
			V.clear(); dfs(i);
			sort (V.begin(), V.end());
			for (int i = 0; i < V.size() - 1; i++)
				printf("%d, ", V[i]);
			printf("%d\n", V.back());
		}
	return 0;
}

