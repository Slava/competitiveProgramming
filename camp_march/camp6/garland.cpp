#include <cstdio>

unsigned int n, x = 1, pow = -1;
int main ()
{
	for (scanf ("%u", &n); n; n >>= 1)
		pow += n & 1;
	x <<= pow;
	printf("%u", x);
	return 0;
}

