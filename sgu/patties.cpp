// 184
#include <cstdio>

int a, b, c, x, y, z;
int main ()
{
	scanf ("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
	a /= x; b /= y; c /= z;
	if (b < a)
		a = b;
	if (c < a)
		a = c;
	printf("%d\n", a);
	return 0;
}

