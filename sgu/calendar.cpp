#include <cstdio>

int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a, b, x, y, d;
int main ()
{
	scanf ("%d%d", &a, &b);
	if (b > 12 || a > m[b - 1])
	{
		puts("Impossible");
		return 0;
	}
	x = 1, y = 1;
	while (x != a || y != b)
	{
		d++;
		x++;
		if (x > m[y - 1])
		{
			x = 1;
			y++;
		}
	}
	printf("%d\n", d % 7 + 1);
	return 0;
}

