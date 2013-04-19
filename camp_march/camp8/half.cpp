#include <cstdio>
#define bit(x,y) (((x)>>(y))&1)

int mask, n, l[900], r[900], m, ans = 1 << 30, mans;
void check ()
{
	int R = 0;
	for (int i = 0; i < m; i++)
		if (bit(mask, l[i] - 1) != bit(mask, r[i] - 1))
			R++;
	if (R < ans)
	{
		ans = R;
		mans = mask;
	}
}

void show (int x)
{
	for (int i = 0; i < n; i++)
		printf("%d", bit(x,i));
	puts("");
}

void rec (int i, int l)
{
	if (i == n)
	{
		if (l)
			return;
//		show (mask);
		check();
		return;
	}
	if (n - i == l)
	{
		mask |= (1 << i);
		rec(i + 1, l - 1);
		mask ^= (1 << i);
		return;
	}
	rec (i + 1, l);
	if (l)
	{mask |= (1 << i);
	rec (i + 1, l - 1);
	mask ^= (1 << i);}
}

int main ()
{
	freopen ("half.in", "r", stdin);
	freopen ("half.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf ("%d%d", l + i, r + i);
	rec(0, n / 2);
	for (int i = 0; i < n; i++)
		if (bit(mans, i))
			printf("%d ", i + 1);
	return 0;
}

