// 135
#include <cstdio>

long long n;
int main ()
{
	scanf ("%I64d", &n);
	n = n * (n + 1) / 2 + 1;
	printf ("%I64d", n);
	return 0;
}

