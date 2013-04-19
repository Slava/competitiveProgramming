#include <cstdio>

#ifdef WIN32
#define i64 "%I64d"
#else 
#define i64 "%Ld"
#endif

long long x, k, bit, j = 63, sum;
long long fact(long long j)
{
	if (k > j)
		return 0;
	long long s = 1, i;
	for (i = k + 1; i <= j; i++)
		s *= i;
	for (i = 1; i <= j - k; i++)
		s /= i;
	return s;
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf (i64 i64, &x, &k);
	x++;
	for (bit = (1ll << 62);bit > x; bit >>= 1)
		j--;
	for (; bit; bit >>= 1, j--)
		if (bit & x)
			sum += fact(j - 1);
		else k--;
	printf(i64, sum);
	return 0;
}

