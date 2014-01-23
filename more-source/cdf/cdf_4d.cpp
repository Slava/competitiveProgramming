#include <cstdio>

const int N = 10009;
int n, w[N], h[N], to[N], u[N], d[N];

int dfs(int v)
{
	if(u[v])
		return d[v];
	u[v] = 1;
	for (int i = 0; i < n; i++)
		if (h[i] > h[v] && w[i] > w[v])
			if (dfs(i) + 1 > d[v])
			{
				to[v] = i;
				d[v] = d[i] + 1;
			}
	return d[v];
}

int main ()
{
	scanf ("%d", &n);
	int i;n++;
	for (i = 0; i < n; i++)
	{
		scanf ("%d%d", w + i, h + i);
		to[i] = -1;
	}
	dfs(0);
	printf("%d\n", d[0]);
	for (i = to[0]; i != -1; i = to[i])
		printf("%d ", i);

	return 0;
}

