#include <cstdio>

main ()
{
	int n;
	scanf ("%d", &n);
	puts(n&1 || n < 4 ? "NO" : "YES");
}

