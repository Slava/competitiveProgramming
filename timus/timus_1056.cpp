#include <cstdio>
#include <cstring>

const int N = 100100;
const int logN = 30;
int d[N][logN], h[N], n;
int he[N], ne[N], e[N], w[N], nn;
int list[N * 2], mm, dist[N], f[N * 2];
int Ans[N], ans, mmm, log2[N * 2], u[N];

inline int max(int i, int j) { return i < j ? j : i; }
void dfs (int v, int p = -1)
{
	u[v] = 1;
	if (p != -1)
		h[v] = h[p] + 1;
	list[mm++] = v;
	for (int i = he[v]; i != -1; i = ne[i])
	{
		int to = e[i];
		if (u[to])continue;
		dist[to] = dist[v] + w[i];
		dfs(to, v);
		list[mm++] = v;
	}
}

int rmq (int l, int r)
{
	int k = log2[r - l + 1];
	if (h[d[l][k]] < h[d[r - (1 << k) + 1][k]])
		return d[l][k];
	else return d[r - (1 << k) + 1][k];
}

void init_st ()
{
	for (int i = 0; i < mm; i++)
		d[i][0] = list[i];
	for (int j = 1; 1 << j <= mm; j++)
		for (int i = 0; i + (1 << j) - 1 < mm; i++)
			if (h[d[i][j - 1]] < h[d[i + (1 << (j - 1))][j - 1]])
				d[i][j] = d[i][j - 1];
			else d[i][j] = d[i + (1 << (j - 1))][j - 1];
}

int lca(int l, int r) {
	l = f[l]; r = f[r];
	if (l > r) {
		l = l + r;
		r = l - r;
		l = l - r;
	}
	return rmq(l, r);
}

int main ()
{
	scanf ("%d", &n); memset(ne, ~0, sizeof ne); memset(he, ~0, sizeof he);
	for (int i = 1, j = 0; i <= n * 2; i++) {
		while((1 << j) <= i)j++;
		log2[i] = j - 1;
	}
	for (int i = 1, x, y, z; i < n; i++)
	{
		scanf("%d", &x); x--; y = i; z = 1;
		e[nn] = y; w[nn] = z;
		ne[nn] = he[x]; he[x] = nn++;
	}
	dfs(0);
	init_st();
	for (int i = mm - 1; i >= 0; i--)
		f[list[i]] = i;
	ans = (1 << 30);
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			s = max(s, dist[i] + dist[j] - 2 * dist[lca(i, j)]);
		}
		if (s < ans) {
			ans = s;
			mmm = 0;
		}
		if (s == ans)
			Ans[mmm++] = i + 1;
	}
	for (int i = 0; i < mmm; i++)
		printf("%d ", Ans[i]);
	return 0;
}

