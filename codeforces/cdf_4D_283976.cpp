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





// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Feb 13, 2011 2:31:37 PM
// contest: 4
// link: /contest/4/submission/283976
// time: 160 ms
// verdict: Accepted
// problem: 4D - Mysterious Present
// ID: 283976
// downloaded by very stupid script
