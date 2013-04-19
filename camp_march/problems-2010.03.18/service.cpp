#include <cstdio>
#include <cstring>

const int N = 201;
const int M = 1001;
int n, m, g[N][N],
	a[2][N][N][N],
	q[M], ans, inf 
	;

int main ()
{
	freopen ("service.in", "r", stdin);
	freopen ("service.out", "w", stdout);

	ans = inf = (1 << 30);
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &g[i][j]);
	for (int i = 0; i < m; i++)
		scanf ("%d", q + i);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				a[0][i][j][k] = inf;
	a[0][0][1][2] = 0;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				for (int l = 0; l < n; l++)
					a[(i + 1)&1][j][k][l] = inf;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				for (int l = 0; l < n; l++)
					if (a[i&1][j][k][l] != inf)
					{
						int Q = q[i] - 1;
						if (a[(i + 1)&1][Q][k][l] > a[i&1][j][k][l] + g[j][Q])
							a[(i + 1)&1][Q][k][l] = a[i&1][j][k][l] + g[j][Q]
						 ;
						if (a[(i + 1)&1][j][Q][l] > a[i&1][j][k][l] + g[k][Q])
							a[(i + 1)&1][j][Q][l] = a[i&1][j][k][l] + g[k][Q]
						 ;
						if (a[(i + 1)&1][j][k][Q] > a[i&1][j][k][l] + g[l][Q])
							a[(i + 1)&1][j][k][Q] = a[i&1][j][k][l] + g[l][Q]
						 ;
					}
	}
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			for (int l = 0; l < n; l++)
				ans = ans > a[m&1][j][k][l] ? a[m&1][j][k][l] : ans;
	printf("%d\n", ans);
	
	return 0;
}

