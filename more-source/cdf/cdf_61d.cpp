#include <cstdio>
#include <vector>
#define pb push_back

using namespace std;

const int N = 101010;
long long sum[N], mx, ans;
vector<int>g[N], a[N];
int n;
void dfs (int v, int p, long long d)
{
	sum[v] = d;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p)
			continue;
		dfs(to, v, sum[v] + (long long)a[v][i]);
	}
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		scanf ("%d%d%d", &x, &y, &z);
		a[x].pb(z);g[x].pb(y);
		a[y].pb(z);g[y].pb(x);
		ans += (long long)z;
	}
	ans *= 2LL;
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++)
		mx = sum[i] > mx ? sum[i] : mx;
	ans -= mx;
	printf("%I64d", ans);
	return 0;
}

