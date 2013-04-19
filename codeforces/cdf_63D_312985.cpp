#include <cstdio>


char a[200][200], p = 'a' - 1;
int n1, n2, m1, m2, x, y, le, n, d, F, nmx;
int main ()
{
	scanf ("%d%d%d%d%d", &m1, &n1, &m2, &n2, &n);
	nmx = n1 > n2 ? n1 : n2;
	x = m1 + (n2 & 1 ? m2 : 1);
	d = n2 % 2 == 0; F = 1;
	y = n2;
	do
	{
		if (!le)
		{
			n--;
			p++;
			scanf ("%d", &le);
		}
		le--;
		a[y][x] = p;
		if (x == m1 + 1 && y == 1)
			F = !F, x--;
		else if ((x == m1 + m2 && d) || (x == m1 + 1 && !d) || (x == 1 && !d) || (x == m1 && d))
		{
			if (F)
				y--;
			else y++;
			d = !d;
		}
		else x += d ? 1 : -1;
	}
	while (n || le);
	puts("YES");
	for (int i = 1; i <= nmx; i++)
	{
		for (int j = 1; j <= m1 + m2; j++)
			if(a[i][j])
				printf("%c", a[i][j]);
			else putchar('.');
		printf("\n");
	}
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Mar 1, 2011 9:01:16 AM
// contest: 63
// link: /contest/63/submission/312985
// time: 30 ms
// verdict: Accepted
// problem: 63D - Dividing Island
// ID: 312985
// downloaded by very stupid script
