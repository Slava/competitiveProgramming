#include <cstdio>
#include <vector>

using namespace std;

int cyc_start, cyc_end, n, m, ans;
vector<int>g[200], u, p, cyc;

bool dfs(int v)
{
	u[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!u[to]){
			p[to] = v;
			if(dfs(to))
				return true;
		}
		else if (u[to] == 1)
		{
			cyc_end = v;
			cyc_start = to;
			return true;
		}
	}
	u[v] = 2;
	return false;
}

int main ()
{
	freopen("contest.dat", "r", stdin);
	freopen("contest.sol", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
	}
	cyc.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		u.assign(n + 1, 0);
		p.assign(n + 1, -1);
		cyc_start = -1;
		dfs(i);
//		printf("new dfs:\n");
		if (cyc_start != -1){
			for (int v = cyc_end; v != cyc_start; v = p[v])
			{
				cyc[v] = 1;
//				printf("%d ", v);
			}
			cyc[cyc_start] = 1;//printf("%d\n", cyc_start);
		}
	}
	for (int i = 1; i <= n; i++)
		ans += cyc[i];
	printf("%d", ans);
	return 0;
}

