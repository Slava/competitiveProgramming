#include <cstdio>
#include <cstring>

const int N = 100100;
const int logN = 30;
int d[N][logN], h[N], n, log2[N * 2];
int he[N], ne[N], e[N], w[N], nn;
int list[2 * N], mm, dist[N], f[2 * N];

void dfs (int v, int p = -1)
{
	if (p != -1)
		h[v] = h[p] + 1;
	list[mm++] = v;
	for (int i = he[v]; i; i = ne[i])
	{
		int to = e[i];
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

int lca (int i, int j) {
	i = f[i]; j = f[j];
	if (i > j) i += j, j = i - j, i = i - j;
	return rmq(i, j);
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

int main ()
{
	scanf ("%d", &n);
	for (int i = 1, j = 0; i <= n * 2; i++) {
		while((1 << j) <= i)j++;
		log2[i] = j;
	}
	for (int i = 1, x, y, z; i < n; i++)
	{
		scanf ("%d%d%d", &x, &y, &z);
		x--, y--;
		e[nn] = y; w[nn] = z;
		ne[nn] = he[x]; he[x] = nn++;
	}
	dfs(0);
	init_st();
	for (int i = mm - 1; i >= 0; i--)
		f[list[i]] = i;
	return 0;
}

