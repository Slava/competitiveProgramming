// 131
#include <cstdio>
#define bit(x,i) ((x >> i)&1)

int n, m, t;
unsigned long long a[11][1 << 10];

void showmask (int x)
{
	for (int i = 0; i < m; i++)
		printf("%d", bit(x, i));
}

void go (int x, int y, int mask, int nwmask = 0)
{
	if (y >= m)
	{
		a[x + 1][nwmask] += a[x][mask];
		return;
	}
	if (bit(mask, y))
		go (x, y + 1, mask, nwmask);
	else 
	{
		if (!bit(nwmask, y))
			go(x, y + 1, mask, nwmask | (1 << y));
		if (y + 1 < m && !bit(mask, y + 1))
			go(x, y + 2, mask, nwmask);
		if (y + 1 < m)
		{
			if (!bit(nwmask, y) && !bit(nwmask, y + 1))
				go(x, y + 1, mask, nwmask | (1 << y) | (1 << (y + 1)));
			if (!bit(mask, y + 1) && !bit(nwmask, y + 1))
				go(x, y + 2, mask, nwmask | (1 << (y + 1)));
			if (!bit(nwmask, y) && !bit(mask, y + 1))
				go(x, y + 2, mask, nwmask | (1 << y));
		}
		if (y - 1 >= 0 && !bit(nwmask, y - 1) && !bit(nwmask, y))
			go(x, y + 1, mask, nwmask | (1 << y) | (1 << (y - 1)));
	}
}

int main ()
{
	scanf ("%d%d", &n, &m);
	if (n < m)
		t = n, n = m, m = t;
	a[0][0] = 1;
	for (int j = 0; j < n; j++)
		for (int i = 0; i < (1 << m); i++)
			go(j, 0, i);
	printf("%I64d\n", a[n][0]);
	return 0;
}

