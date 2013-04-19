#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100100;
int n, r, d[N], z[N], ex[N], ey[N], ansx, ansy;
vector<int>g[N];

int dfs(int v, int p) {
	z[v] = -1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (to == p) continue;
		d[v] ^= 1 + dfs(to, v);
		z[v]++;
	}
	return d[v];
}

void out(int v, int p, int k) {
	int n = d[v], to = -1, R = k;
	for (int i = 0; i < (int)g[v].size(); i++) {
		to = g[v][i];
		if (to == p) continue;
		R = n ^ k ^ (d[to] + 1);
		if (R < d[to] + 1)
			break;
	}
	if (!R) { ansx = v; ansy = to; return; }
	out(to, v, R - 1);
}

int main() {
	scanf("%d%d", &n, &r);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		if (x > y)swap(x, y);
		ex[i] = x; ey[i] = y;
	}
	if (dfs(r, 0)) {
		printf("1\n");
		out(r, 0, 0);
		if (ansx > ansy)
			swap(ansx, ansy);
		for (int i = 1; i < n; i++)
			if (ex[i] == ansx && ey[i] == ansy) {
				printf("%d\n", i);
				break;
			}
	}
	else printf("2\n");
	return 0;
}
