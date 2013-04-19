#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[100], ans, sum;
int main ()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i), sum += a[i];
	sort(a, a + n);
	sum -= a[n - 1];
	while (n > 2 && sum <= a[n - 1])
	{
		n--;ans++;
		sum -= a[n - 1];
	}
	if (n < 3)printf("-1");
	else printf("%d", ans);
}

