// slavko - myasko
#include <cstdio>
#define bit(x,y) (((x)>>(y))&1)
#define max(x,y) (x>y?x:y)

struct L
{
	int a[1000], n;
	L () {n = 1; a[0] = 0;}
	void operator += (L b)
	{
		int c = 0;
		for (int i = 0; i < max(n, b.n) || c; i++)
		{
			if (i + 1 > n)
				n = i + 1;
			a[i] += b.a[i] + c;
			c = a[i] / 10;
			a[i] %= 10;
		}
	}
	void print()
	{
		for (int i = n - 1; i >= 0; i--)
			printf("%d", a[i]);printf("\n");
	}
};

int n;
L a[8][1010];

void go (int x, int y, int m, int nm)
{
	if (y == 3)
	{
		a[nm][x + 1] += a[m][x];
		return;
	}
	go(x, y + 1, m, nm);
	if (!bit(m,y))
	{
		go(x, y + 1, m, nm | (1 << y));
		if (!bit(m, y + 1) && y + 1 < 3)
			go(x, y + 2, m, nm);
	}
}

int main ()
{
	freopen ("mayor.in", "r", stdin);
	freopen ("mayor.out", "w", stdout);
	
	scanf("%d", &n);
	a[0][0].a[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 8; j++)
			go(i, 0, j, 0);
	a[0][n].print();
	return 0;
}

