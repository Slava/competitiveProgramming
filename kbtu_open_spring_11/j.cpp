#include <cstdio>
#define bit(x,y) (((x)>>(y))&1)

int n, x, m, fool = 1;
int u[22], k[22], onlyone = ((1 << 22) - 1), onlyzero, ans[22];
void go (int mask)
{
	for (int i = 0; i < n; i++)
		if (bit(mask, i))
		{
			if (i - 1 >= 0)
				k[i - 1]++;
			k[i]++; k[i + 1]++;
		}
		int good = 1;
	for (int i = 0; i < n; i++)
		if (k[i] != u[i]) good = 0;
	for (int i = 0; i < n; i++)
		k[i] = 0;
	if (good)
		onlyone &= mask,
		onlyzero |= mask,
		fool = 0;
}

int main ()
{
	freopen ("minesweeper.in", "r", stdin);
	freopen ("minesweeper.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", u + i);
	}
	for (int i = 0; i  <(1<<n); i++)
		go(i);
	if (fool)
	{
		puts("Fool's Day is over!");
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (!bit(onlyone,i) && bit(onlyzero,i))
			ans[i] = 2;
		else if (!bit(onlyone,i) && !bit(onlyzero,i))
			ans[i] = 0;
		else ans[i] = 1;
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
}

