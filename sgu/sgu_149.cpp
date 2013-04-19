#include <cstdio>
#include <cstring>
//#pragma comment(linker, "/stack:64000000")
#define max(a,b) ((a)>(b)?(a):(b))

const int N = 10100;
int he[N], ne[N], e[N], w[N], nn, n;
int p[N], pw[N], d1[N], d1v[N], d2[N], d3[N];

void dfs_down(int v) {
	for (int i = he[v]; i != -1; i = ne[i])
		dfs_down(e[i]);
	for (int i = he[v]; i != -1; i = ne[i])
		if (d1[v] < w[i] + d1[e[i]]) {
			d1[v] = w[i] + d1[e[i]];
			d1v[v] = e[i];
		}
	for (int i = he[v]; i != -1; i = ne[i])
		if (e[i] != d1v[v] && d2[v] < w[i] + d1[e[i]])
			d2[v] = w[i] + d1[e[i]];
}

void dfs_up(int v) {
	if (p[v] != v)
		d3[v] = pw[v] + max(d3[p[v]], (v == d1v[p[v]]) ? d2[p[v]] : d1[p[v]]);
	for (int i = he[v]; i != -1; i = ne[i])
		dfs_up(e[i]);
}

int main ()
{
	scanf ("%d", &n); 
	memset(ne, ~0, sizeof ne); memset(he, ~0, sizeof he);
	for (int i = 1, x, y, z; i < n; i++)
	{
		scanf("%d%d", &x, &z); x--; y = i;
		e[nn] = y; w[nn] = z;
		ne[nn] = he[x]; he[x] = nn++;
		p[i] = x; pw[i] = z;
	}
	dfs_down(0);
	dfs_up(0);
	for (int i = 0; i < n; i++)
		printf("%d\n", max(d1[i], d3[i]));
	return 0;
}

