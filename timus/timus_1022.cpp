#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n, x, u[110];
vector<int> g[110], l;

void dfs(int v) {
	u[v] = 1;
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++)
		if (!u[*i])
			dfs(*i);
	l.push_back(v);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for(;;) {
			scanf("%d", &x);
			if (!x)break;
			g[i].push_back(x - 1);
		}
	for (int i = 0; i < n; i++)
		if (!u[i])
			dfs(i);
	for (int i = l.size() - 1; i >= 0; i--)
		printf("%d ", l[i] + 1);
	return 0;
}
