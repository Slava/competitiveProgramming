// 133
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
ii a[32000];
int n, ans, i, r;
int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
		scanf ("%d%d", &a[i].first, &a[i].second);
	sort(a, a + n);
	r = a[0].second;
	for(i = 1; i < n; i++)
		if (a[i].second <= r)
			ans++;
		else r = a[i].second;
	printf("%d\n", ans);
	return 0;
}

