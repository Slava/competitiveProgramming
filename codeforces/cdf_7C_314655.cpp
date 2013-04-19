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





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Mar 3, 2011 2:50:33 PM
// contest: 7
// link: /contest/7/submission/314655
// time: 30 ms
// verdict: Accepted
// problem: 7C - Line
// ID: 314655
// downloaded by very stupid script
