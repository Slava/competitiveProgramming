#include <cstdio>
#include <cstring>
#include <vector>

const int N = 101010;
int n, p[N], ls[N], lst, u[N], comp, P[N], U[N], min, h, t, q[N];
std::vector<int> g[N];

void dfs(int v) {
	t = 0;
	q[t++] = v;
	while (t > 0) {
		v = q[t - 1];
		u[v] = 1;
		if (!u[p[v]])
			q[t++] = p[v];
		else ls[lst++] = v, t--;
	}
}

void col(int v) {
	h = t = 0;
	q[t++] = v;
	while (h < t) {
		v = q[h++];
		u[v] = comp;
		for (int i = 0; i < (int)g[v].size(); i++) {
			int to = g[v][i];
			if (!u[to]) {
				u[to] = comp;
				q[t++] = to;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
		g[p[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (!u[i])
			dfs(i);
	memset(u, 0, sizeof u);

	for (int i = lst - 1; i >= 0; i--)
		if (!u[ls[i]]) {
			comp++;
			col(ls[i]);
		}

	for (int i = 1; i <= n; i++)
		if (u[i] != u[p[i]])
			P[u[i]] = u[p[i]],
			U[u[p[i]]] = 2;
	for (int i = 1; i <= comp; i++)
		if (!U[i]) {
			int v = i;
			min++;
			U[v] = 2;
			while (U[v] == 2) {
				U[v] = 1;
				v = P[v];
			}
		}
	
	printf("%d %d\n", min, comp);

	return 0;
}

