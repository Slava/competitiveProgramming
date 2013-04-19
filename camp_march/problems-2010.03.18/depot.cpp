#include <cstdio>
#include <vector>

using namespace std;

const int N = 410;
int n, m, a[N][N], ptr[N], curans;
int is[N][N], flag, ans, was[N][N];
vector<int>g[N];

void euler (int v)
{
	for (; g[v].size();)
	{
		curans++;
		int to = g[v].back();
		g[v].pop_back();
		euler(to);
	}
}

int main ()
{
	freopen ("depot.in", "r", stdin);
	freopen ("depot.out", "w", stdout);

	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf ("%d", &a[i][j]);
			a[i][j]--;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			is[i][a[i][j]]++, was[i][a[i][j]] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!was[i][j])
			{
				flag = 1;
				for (int k = 0; flag && k < n; k++)
					if (is[k][j] > 1)
					{
						is[k][j]--;
						g[i].push_back(k);
						flag = 0;
					}
				was[i][j] = 1;
			}
	for (int i = 0; i < n; i++)
		if (g[i].size())
		{
			curans = 0;
			euler(i);
			ans += curans + 1; 
		}
	printf("%d\n", ans);
	return 0;
}

