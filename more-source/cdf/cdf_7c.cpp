#include <cstdio>

long long gcd (long long a, long long b, long long &x, long long &y)
{
	if (!a)
	{
		x = 0; y = 1;
		return b;
	}
	long long x1, y1, g;
	g = gcd(b%a, a, x1, y1);
	y = x1;
	x = y1 - (b / a) * x1;
	return g;
}

int main ()
{
	long long a, b, c, x, y, g, h;
	scanf("%I64Ld%I64Ld%I64Ld", &a, &b, &c);
	c = -c;
	g = gcd(a, b, x, y);
	h = c / g;
	if (c % g == 0)
		printf("%I64Ld %I64Ld\n", x * h, y * h);
	else puts("-1");
	return 0;
}

