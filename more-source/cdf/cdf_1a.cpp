#include <cstdio>

int main ()
{
	long long a, b, c;
	scanf ("%I64d%I64d%I64d", &a, &b, &c);
	printf("%I64d", (a/c + (a%c != 0)) * (b/c + (b%c != 0)));
	return 0;
}

