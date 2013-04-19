// 297
#include <cstdio>

int n, m, s, x, i;
int main ()
{
	scanf ("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf ("%d", &x);
		s += x;
		s %= n;
	}
	printf("%d", s);
	return 0;
}

