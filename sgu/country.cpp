#include <cstdio>
#include <cstring>

const int N = 200010;
int n, m, a[N], b[N];
int p[N], e[N], ne[N], neig[N];
int v, vr[N];

int fromv (int x)
{
	if (x == v)
		return 0;
	if (e[vr[x]])
		return 1;
	if (e[ne[x]] && e[vr[neig[x]]])
		return 2;
	return -100;
}

int main ()
{
	scanf ("%d %d\n", &n, &m);
	for (int i = 0, x, y; i < m; i++)
	{
		scanf ("%d %d\n", a + i, b + i);
		e[i] = 1;
		p[a[i]]++, p[b[i]]++;
	}
	for (int i = 1; i <= n; i++)
		if (p[i] > p[v])
			v = i;
	for (int i = 0; i < m; i++)
		if (a[i] == v)
			vr[b[i]] = i;
		else if (b[i] == v)
			vr[a[i]] = i;
		else 
		{
			neig[a[i]] = b[i];
			neig[b[i]] = a[i];
			ne[a[i]] = ne[b[i]] = i;
		}
	char cmd[200];
	int x, y;
	while (scanf ("%s ", cmd) == 1)
	{
		if (cmd[0] == 'L')
		{
			scanf ("%d %d\n", &x, &y);
			int ans = fromv(x) + fromv(y);
			if (x == y)
				printf("0\n");
			else if (x == neig[y] && e[ne[x]])
				printf("1\n");
			else if (ans < 0)
				printf("-1\n");
			else printf("%d\n", ans);
		}
		else 
		{
			scanf ("%d\n", &x);
			e[x - 1] = 0;
		}
	}
	return 0;
}


