#include <cstdio>
#define min(a,b) (a<b?a:b)

const int N = 10010;
int a[N], d[N][2], n;
int main ()
{
	freopen ("zigzag.in", "r", stdin);
	freopen ("zigzag.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", a + i);
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] < a[i])
			d[i][0] = d[i - 1][1];
		else d[i][0] = d[i - 1][0] + 1;
		if (a[i - 1] > a[i])
			d[i][1] = d[i - 1][0];
		else d[i][1] = d[i - 1][1] + 1;
	}
	printf("%d", min(d[n - 1][0], d[n - 1][1]));
	return 0;
}

