#include <cstdio>

int n, a[1010], b[1010], ans;
int main ()
{
	freopen ("LIARS.DAT", "r", stdin);
	freopen ("LIARS.SOL", "w", stdout);
	
	scanf ("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", a + i);
		b[a[i]]++;
	}
	
	for (int i = 1; i <= n; i++)
		if (b[i] == i)
			ans++;
	if (ans == 1)
		ans = 0;
	printf ("%d\n", ans);

	return 0;
}

