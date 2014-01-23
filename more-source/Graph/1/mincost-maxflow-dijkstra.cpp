#include <cstdio>
#include <vector>

using namespace std;
#define pb push_back

const int N = 100;
struct edge
{
	int x, y, cost;
	int f, c;
}a[N*N];
int n, m, inf = (1 << 30);
int d[N], u[N], phi[N], from[N];
vector<int> g[N];

void add_edge (int x, int y, int z, int c)
{
	a[m].x = x; a[m].y = y; a[m].cost = z; a[m].c = c; a[m].f = 0; m++;
	g[x].pb(m - 1);
	a[m].x = y; a[m].y = x; a[m].cost = -z; a[m].c = 0; a[m].f = 0; m++;
	g[y].pb(m - 1);
}

bool dijkstra (int s, int t)
{
	for (int i = 0; i < n; i++)
		u[i] = 0, d[i] = inf, from[i] = -1;
	d[s] = 0;
	while (true)
	{
		int v = -1;
		for (int i = 0; i < n; i++) 
			if (!u[i] && (v == -1 || d[v] > d[i]))
				v = i;
		if (v == -1 || d[v] == inf)
			break;
		u[v] = 1;
		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			int x = v, y = a[to].y, z = a[to].cost,
				f = a[to].f, c = a[to].c;
			if (c - f <= 0)
				continue;
			if (d[y] > d[x] + phi[x] - phi[y] + z){
				d[y] = d[x] + phi[x] - phi[y] + z;
				from[y] = to;
			}
		}
	}
	return u[t];
}

int mincost_maxflow (int s, int t)
{
	int flow, cost;
	flow = cost = 0;
	for (int i = 0; i < n; i++)
		phi[i] = 0;
	while (true)
	{
		if (!dijkstra(s, t))
			break;
		for (int i = 0; i < n; i++)
			phi[i] += d[i];
		int v = t, mx = 0, u, k;
		for (;from[v] != -1; v = u)
		{
			k = from[v];
			u = a[k].x;
			mx = min(mx, a[k].c - a[k].f);
		}
		for (v = t; from[v] != -1; v = u)
		{
			k = from[v];
			u = a[k].x;
			cost += a[k].cost * mx;
			a[k].f += mx;
			a[k^1].f -= mx;
		}
		flow += mx;
	}
}

int main ()
{
	int M, x, y, z, c;
	scanf ("%d%d", &n, &M);
	while (M--)
	{
		scanf ("%d%d%d%d", &x, &y, &z, &c);
		add_edge (x, y, z, c);
	}	
	return 0;
}


