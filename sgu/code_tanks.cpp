// 316
#include <cstdio>

int n, m;
int a[500], b[500], x, y;
int main ()
{
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		a[i] = 100;
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d", &x, &y);
		if (a[y] > 0)
			b[x] += 3;
		a[y] -= 8;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > 0)
			b[i] += a[i] / 2;
		printf("%d %d\n", a[i], b[i]);
	}
	return 0;
}

