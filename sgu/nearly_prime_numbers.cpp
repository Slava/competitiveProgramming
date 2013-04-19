// 113
#include <cstdio>

int euler (int n)
{
	int r = 0;
	for (int i = 2; i * i <= n; i++)
		while (n % i == 0)
			n /= i, r++;
	if (n > 1)
		r++;
	return r;
}

int main ()
{
	int n, x;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &x);
		x = euler(x);
		if (x == 2)
			puts("Yes");
		else puts("No");
	}
	return 0;
}

