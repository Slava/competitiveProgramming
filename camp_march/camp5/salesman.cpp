#include <cstdio>

const int N = 510;
const double inf = 1e9;
int n, m, i, j, u[N], can[N][N], k;
double h[3], price[3], tax[N][3], a[N][N], d[N], take[3], curd, ans;
int main ()
{
	scanf ("%d%d", &n, &m);
	for (i = 0; i < 3; i++)
		scanf ("%lf", h + i);
	for (i = 0; i < 3; i++)
		scanf ("%lf", price + i);
	for (i = 1; i < n - 1; i++)
		for (j = 0; j < 3; j++)
			scanf ("%lf", &tax[i][j]);
	for (i = 0; i < m; i++)
	{
		int f, t;
		scanf ("%d%d", &f, &t);
		can[f - 1][t - 1] =  1;
		scanf ("%lf", &a[f - 1][t - 1]);
	}
	for (m = 0; m < 8; m++)
	{
		for (i = 0; i < N; i++)
			d[i] = inf, u[i] = 0;
		d[0] = 0;
		for (i = 0; i < 3; i++)
			take[i] = (m >> i) & 1 ? h[i] : 0;
		for (i = 0; i < n; i++)
		{
			int mn = - 1;
			for (j = 0; j < n; j++)
				if (!u[j] && (mn == -1 || d[j] < d[mn]))
					mn = j;
			u[mn] = 1;
			for (j = 0; j < n; j++) if (can[mn][j])
			{
				curd = a[mn][j];
				for (k = 0; k < 3; k++)
					curd += take[k] * tax[j][k] * price[k] / 100.0;
				if (curd + d[mn] < d[j])
					d[j] = curd + d[mn];
			}
		}
		double sum = 0;
		for (i = 0; i < 3; i++)
			sum += take[i] * price[i];
		if (ans < sum - d[n - 1])
			ans = sum - d[n - 1];
	}
	printf("%.2lf\n", ans);
	return 0;
}

