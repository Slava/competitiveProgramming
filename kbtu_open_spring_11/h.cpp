#include <cstdio>

int a;
int main ()
{
	freopen ("french.in", "r", stdin);
	freopen ("french.out", "w", stdout);
	scanf ("%d", &a);
	int b = 0;
	for (;a; a>>= 1)
		b+=(a&1);
	printf("%d\n", b);
}

