// 154
#include <cstdio>

int bsearch (int x)
{
	int m, l, r, res, n;
	l = 0; r = 100000000;
	while (l <= r)
	{
		m = (l + r) >> 1;
		res = 0;
		for (n = m; n; n /= 5)
			res += n;
		if (res == x)
			return m;
		if (res > x)
			r = m - 1;
		if (res < x)
			l = m + 1;
	}
	return 0;
}

int main ()
{
	int q, a;
	scanf ("%d", &q);
	if (!q)
	{
		puts("1");
		return 0;
	}
	a = bsearch(q);
	if (a)
		printf("%d\n", a * 5);
	else puts("No solution");
	return 0;
}

