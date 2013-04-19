#include <cstdio>

bool a[30][30];
int n, m, p, q, x, i, j, k, l, ans;

int main ()
{
	freopen ("pattern.in", "r", stdin);
	freopen ("pattern.out", "w", stdout);

	scanf ("%d%d%d%d%d", &n, &m, &q, &p, &x);
	while(x--)
	{
		scanf("%d", &i); i--;
		a[i / m][i % m] = 1;
	}
	for (i = 0; i + q <= n; i++)
		for (j = 0; j + p <= m; j++)
		{
			x = 1;
			for (k = 0; k < q && x; k++)
				for (l = 0; l < p && x; l++)
					if (a[i + k][j + l] != a[k][l])
						x = 0;
			ans += x;
		}
	printf("%d", ans);
	return 0;
}

