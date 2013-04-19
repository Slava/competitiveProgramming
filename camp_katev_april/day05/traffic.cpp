#include <cstdio>

const int N = 200;
int s, f, n, m, a[N*6], b[N*6], w[N*6], 
arom[N][N], from[N][N], d[N][N], p[N][N],
ans[N][N], fans[N][N], inf = (1 << 30),
frw[N][N], arw[N][N];

void prway (int st, int v, int day)
{
	if (v == st)
		return;
	if (day & 1)
	{
		int fr = from[st][v];
		prway(st, fr, day);
		printf("%d %d %d %d\n", fr + 1, v + 1, day, frw[st][v]);
	}
	else
	{
		int fr = arom[st][v];
		prway(st, fr, day);
		printf("%d %d %d %d\n", fr + 1, v + 1, day, arw[st][v]);
	}
}

void prans (int day, int v)
{
	if (v == s)
		return;
	prans(day - 1, fans[day][v]);
	prway(fans[day][v], v, day);
//	printf("-->> %d %d\n", fans[day][v], v);
}

int main ()
{
	freopen ("traffic.in", "r", stdin);
	freopen ("traffic.out", "w", stdout);
	
	scanf("%d%d", &s, &f); s--;f--;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf ("%d%d%d", a + i, b + i, w + i);
		a[i]--, b[i]--;
	}
	for (int i = 0 ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			p[i][j] = d[i][j] = inf;
		d[i][i] = p[i][i] = 0;
		for (int j = 0; j < m; j++){
			if (d[i][b[j]] > d[i][a[j]] + w[j] && d[i][a[j]] + w[j] <= 12)
			{
				d[i][b[j]] = d[i][a[j]] + w[j];
				from[i][b[j]] = a[j];
				frw[i][b[j]] = w[j];
			}
			if (p[i][a[j]] > p[i][b[j]] + w[j] && p[i][b[j]] + w[j] <= 12)
			{
				p[i][a[j]] = p[i][b[j]] + w[j];
				arom[i][a[j]] = b[j];
				arw[i][a[j]] = w[j];
			}
		}
	}
	for (int i = 0; i < n; i++)
		ans[0][i] = inf;
	ans[0][s] = 0;
	for (int i = 1; i < 200; i++)
	{
		for (int j = 0; j < n; j++)
			ans[i][j] = inf;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (i & 1)
				{
					if (ans[i - 1][k] != inf && ans[i][j] > d[k][j])
					{
						ans[i][j] = d[k][j];
						fans[i][j] = k;
					}
				}
				else
				{
					if (ans[i - 1][k] != inf && ans[i][j] > p[k][j])
					{
						ans[i][j] = p[k][j];
						fans[i][j] = k;
					}
				}
		if (ans[i][f] != inf)
		{
			prans(i, f);
			return 0;
		}
	}

	return 0;
}

