// 196
#include <cstdio>

int n, m, p[10100], a[100100], b[100100], ans;
int main ()
{
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d", a + i, b + i);
		p[a[i]]++, p[b[i]]++;
	}
	for (int i = 0; i < m; i++)
		ans += p[a[i]] + p[b[i]];
	printf("%d", ans);
	return 0;
}

