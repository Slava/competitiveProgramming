// 398
#include <cstdio>
#include <vector>

using namespace std;

vector<int>g[60], ans;
int n, k, t, x,
	a[60], f[60];
int main ()
{
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf ("%d", &t);
		for (;t--;)
		{
			scanf ("%d", &x);
			g[i].push_back(x);
			if (i == k)
				a[x] = 1;
		}
	}
	for (int i = 1; i <= n; i++)if (i != k)
		for (int j = 0; j < g[i].size(); j++)
		{
			t = g[i][j];
			if (a[t] && !a[i])
				f[i] = 1;
		}
	for (int i = 1; i <= n; i++)
		if (f[i]) ans.push_back(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}

