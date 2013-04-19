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





// lang: GNU C++
// memory: 8300 KB
// author: imslavko
// submit_date: Feb 23, 2011 8:41:03 AM
// contest: 61
// link: /contest/61/submission/300060
// time: 300 ms
// verdict: Accepted
// problem: 61D - Eternal Victory
// ID: 300060
// downloaded by very stupid script
