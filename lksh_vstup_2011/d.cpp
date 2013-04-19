#include <cstdio>

const int N = 2222;
int n, m, h, t = 1, d[N], gr[N],
	a[N][N], u[N][N * 2], q[N];

int dfs(int x){
	for (int i = 0; i < n; i++)
		if(a[x][i] && d[i] > d[x])
			u[x][dfs(i)] = 1;
	for (int i = 0; i < 2000; i++)
		if (!u[x][i]){
			gr[x] = i;
			break;
		}
	return gr[x];
}

main ()
{
	scanf("%d%d", &n, &m);
	int i, x, y;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[--x][--y] = a[y][x] = 1;
	}
	d[0] = 1;
	while(h < t){
		int cur = q[h++];
		for (i = 0; i < n; i++)
			if(a[cur][i] && !d[i]){
				d[i] = d[cur] + 1;
				q[t++] = i;
			}
	}
	dfs(0);
	puts(gr[0] ? "Vladimir" : "Nikolay");
}

