#include <cstdio>
#include <vector>

using namespace std;

const int N = 110;
int g[7][7], n, a[N][3], power[8], v1, v2, F;
vector<int>ans, res, pl;
#define pb push_back

void path(int v)
{
	for (int i = 0; i <= 6; i++)
		if (g[v][i])
		{
			g[v][i]--;g[i][v]--;
			path(i);
		}
	ans.pb(v);
}

int main ()
{
	v1 = v2 = -1;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf ("%d%d", &a[i][0], &a[i][1]);
		g[a[i][0]][a[i][1]]++;
		g[a[i][1]][a[i][0]]++;
		power[a[i][0]]++;power[a[i][1]]++;
		F = a[i][0];
	}
	int nodd = 0;
	for (int i = 0; i <= 6; i++)
		if (power[i] % 2 == 1)
			if (v1 == -1)
				v1 = i, nodd++;
			else if (v2 == -1)
				v2 = i, nodd++;
			else 
			{
				puts("No solution");
				return 0;
			}
	if (v1 != -1 && v2 != -1)
	{
		g[v1][v2]++, g[v2][v1]++;
		a[0][0] = v1; a[0][1] = v2;
	}
	path(F);ans.pb(ans[0]);
	for (int i = 1; i < ans.size(); i++)
	{
		int v = ans[i - 1], u = ans[i];
		for (int j = 0; j <= n; j++)
			if (a[j][2])continue;
			else if (a[j][0] == v && a[j][1] == u)
			{
				res.pb(j);pl.pb(1);a[j][2] = 1;break;
			}
			else if (a[j][0] == u && a[j][1] == v)
			{
				res.pb(j);pl.pb(0);a[j][2] = 1;break;
			}
	}
	int P = -1;
	for (int i = 0; i < res.size(); i++)
		if (res[i] == 0)
			P = i;
	if (!((P == -1 && res.size() == n) || (P != -1 && res.size() == n + 1)))
	{
		puts("No solution");
		return 0;
	}
	for (int i = P + 1; i < res.size(); i++)
		printf("%d %c\n", res[i], pl[i] ? '+' : '-');
	for (int i = 0; i < P; i++)
		printf("%d %c\n", res[i], pl[i] ? '+' : '-');
	return 0;
}

