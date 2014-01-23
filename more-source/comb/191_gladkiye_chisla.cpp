#include <cstdio>

unsigned long a[70][12], x, upto[70], ans[70], ac;

long sumall (int i)
{
	for (int j = 1; j < 10; j++)
		a[i][0] += a[i][j];
	return a[i][0];
}

void
solve (long x)
{
	x--;
	int i, j;
	i = 1; j = 1;
	for (;;i++)
		if (upto[i] > x)
			break;		
	x -= upto[i - 1];
	while (i){
		for (; j < 10; j++)
		{
			x -= a[i][j];
			if (x < 0)
			{
				x += a[i][j];
				ans[ac++] = j;
				i--;
				break;
			}
		}
	}
	for (i = 0; i < ac; i++)
		printf("%ld", ans[i]);
}

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%ld", &x);
	a[1][9] = 1;
	for (int i = 1; i < 51; i++)
		for (int j = 9; j; j--)
			a[i][j] += a[i - 1][j] + a[i][j + 1];
	for (int i = 1; i < 51; i++)
		upto[i] = upto[i - 1] + sumall(i);
	solve(x);
	return 0;
}

