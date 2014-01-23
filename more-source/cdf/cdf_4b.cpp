#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 40;
int n, fulltime, l[maxn], h[maxn], d[maxn], a, i;

int main ()
{
	scanf ("%d%d", &n, &fulltime);
	for (i = 0; i < n; i++)
		scanf ("%d%d", &l[i], &h[i]);
	for (i = 0; i < n; i++)
	{
		d[i] = l[i];
		fulltime -= l[i];
		if (fulltime < 0)
		{
			puts("NO");return 0;
		}
	}
	for (i = 0; i < n && fulltime; i++)
	{
		a = min(fulltime, h[i] - l[i]);
		fulltime -= a;
		d[i] += a;
	}
	
	if (fulltime)
		puts("NO");
	else
	{
		puts("YES");
		for (i = 0; i < n; i++)
			printf("%d ", d[i]);
	}

	return 0;
}

