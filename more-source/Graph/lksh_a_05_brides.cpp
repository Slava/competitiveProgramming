#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

const int N = 201;
int n, m, k, d[N], path[N],
	inf = (1 << 30);
double M, ans;
vector<int> P[N];

struct rib
{
	int x, y, cost, f;
	rib()
	{
		x = y = cost = f = 0;
	}
}a[N*N];

int cost (int i)
{
	if (a[i].f < 0)
		return -a[i].cost;
	return a[i].cost;
}

bool bellman (int s, int t)
{
	int x, y, i;
	for (i = 1; i <= n; i++)
		path[i] = -1, d[i] = inf;
	d[s] = 0;
	for (i = 0; i < 2 * m; i++)
	{
		if (a[i].f > 0)
			continue;
		x = a[i].x; y = a[i].y; 
		if (d[y] > d[x] + cost(i))
		{
			d[y] = d[x] + cost(i);
			path[y] = i;
		}
	}
	M = d[t];
	return path[t] != -1;
}

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf ("%d%d%d", &x, &y, &z);
		a[i*2].x = x; a[i*2].y = y; a[i*2].cost = z;
		a[i*2+1].x = y; a[i*2+1].y = x; a[i*2+1].cost = z;
	}
	for (int i = 1; i <= k; i++)
	{
		if (!bellman(1,n))
		{
			puts("-1");
			return 0;
		}
		for (int v = n, u, t; path[v] != -1; v = u)
		{
			t = path[v];
			u = a[t].x;
			a[t].f++;
			a[t^1].f--;
			P[i].pb(t / 2 + 1);
		}
		ans += M;
	}
	printf("%.5lf\n", ans / k);
	for (int i = 1; i <= k; i++)
	{
		printf("%d ", P[i].size());
		while (!P[i].empty())
		{
			printf("%d ", P[i].back());
			P[i].pop_back();
		}
		puts("");
	}
	return 0;
}

