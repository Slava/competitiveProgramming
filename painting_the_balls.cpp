#include <cstdio>

#define mod(x) ((x) - ((x)/m) * m)
#define min(a,b) ((a)<(b)?(a):(b))

int d[110][110], n, m, mx = 1 << 30, c[10100];
int main ()
{
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", c + i);
	for (int i = 0; i < m; i++)
		d[1][i] = mx;
	d[1][m - 1] = c[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
			d[mod(i)][j] = mx;
		for (int j = 0; j < m - 1; j++)if (i - j - 1 > 0)
		{
			d[mod(i)][j] = min(d[mod(i - j - 1)][m - 1] + c[i], 
								d[mod(i)][j]);
			d[mod(i)][m - 1] = min(d[mod(i)][m - 1], d[mod(i)][j]);
		}
		for (int j = 0; j < m - 1; j++)
			printf("%d ", d[mod(i)][j]);puts("");
	}
	return 0;
}

