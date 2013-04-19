#include <cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

int n, m, s, f, d[510];
int in[510][260], out[510][260], t[510],
	inn[510], outn[510], inf = (1 << 30);
int main ()
{
	freopen("alchemy.dat", "r", stdin);
	freopen("alchemy.sol", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &s, &f);
	for (int i = s + 1; i <= n; i++)
		d[i] = inf;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", t + i);
		scanf("%d", inn + i);
		for (int j = 0; j < inn[i]; j++)
			scanf ("%d", &in[i][j]);
		scanf("%d", outn + i);
		for (int j = 0; j < outn[i]; j++)
			scanf ("%d", &out[i][j]);
	}
	for (int j = 1; j < n; j++)
		for (int i = 0; i < m; i++)
		{
			int time = 0;
			for (int k = 0; k < inn[i]; k++)
				time = max(time, d[in[i][k]]);
			time += t[i];
			for (int k = 0; k < outn[i]; k++)
				d[out[i][k]] = min(d[out[i][k]], time);
		}
	printf("%d", d[f] == inf ? -1 : d[f]);
	return 0;
}


