#include <cstdio>

long long x, y, p;
#ifdef WIN32
	#define i64 "%I64d"
#else
	#define i64 "%lld"
#endif
long long gcd(long long a, long long b)
{
	while(a && b)
	{
		if (a > b)
			a %= b;
		else b %= a;
	}
	return a + b;
}

int main ()
{
	freopen("triangle.dat", "r", stdin);
	freopen("triangle.sol", "w", stdout);
	
	scanf(i64 i64 i64, &x, &y, &p);
	long long d = gcd(x, y), ans;
	ans = (x * y - (x + y - 1)) / 2;
	ans %= p;
	if (d != 1)
	{
		long long X = x / d, Y = y / d;
		ans = (X * Y - (X + Y - 1)) / 2;
		ans += (d * (d - 1)) / 2 * x / d * y / d;
		ans %= p;
	}
	printf(i64, (p - ans) % p);
	return 0;
}

