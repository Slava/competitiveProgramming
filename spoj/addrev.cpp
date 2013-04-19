#include <cstdio>

void rev (int &a)
{
	int c;
	for (c = 0; a; a /= 10)
	{
		c *= 10;
		c += a % 10;
	}
	a = c;
}

int main ()
{
	int t, a, b;
	scanf ("%d", &t);
	for (;t--;)
	{
		scanf("%d%d", &a, &b);
		rev(a);rev(b); a += b; rev(a);
		printf("%d\n", a);
	}
}

