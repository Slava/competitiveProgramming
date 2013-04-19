#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1009;
int n, zero_exists, zx, zy, i, j, x, y,
	b2[maxn][maxn], b5[maxn][maxn],
	twos[maxn][maxn], fives[maxn][maxn],
	a[maxn][maxn], sc, check_fives;
char s[maxn * 2];

int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf ("%d", &a[i][j]);
			if (!a[i][j])
			{
				zero_exists = true;
				zx = i; zy = j;
				a[i][j] = 10;				
			}
		}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			while (a[i][j] % 2 == 0)
			{
				twos[i][j]++;
				b2[i][j]++;
				a[i][j] >>= 1;
			}
			while (a[i][j] % 5 == 0)
			{
				fives[i][j]++;
				b5[i][j]++;
				a[i][j] /= 5;
			}
			if(!i && !j)
				continue;
			if (i && !j)
				fives[i][j] += fives[i - 1][j],
				twos[i][j] += twos[i - 1][j];
			if (!i && j)
				fives[i][j] += fives[i][j - 1],
				twos[i][j] += twos[i][j - 1];
			if (i && j)
				fives[i][j] += min(fives[i - 1][j], fives[i][j - 1]),
				twos[i][j] += min(twos[i - 1][j], twos[i][j - 1]);
		}
	}
	if (min(twos[n-1][n-1], fives[n-1][n-1]) >=1 && zero_exists)
	{
		printf("1\n");
		for (i = 0; i < zx; i++)
			putchar('D');
		for (i = 0; i < n - 1; i++)
			putchar('R');
		for (i = zx; i < n - 1; i++)
			putchar('D');
	}
	else
	{
		printf("%d\n", min(fives[n-1][n-1], twos[n-1][n-1]));
		sc = 0;
		x = y = n - 1;
		check_fives = (fives[n-1][n-1] < twos[n-1][n-1]);
		while (x || y)
		{
			if (x && (check_fives?fives[x-1][y] + b5[x][y] == fives[x][y] : 
								  twos[x-1][y] + b2[x][y] == twos[x][y])) 
					s[sc++] = 'D', x--;
			else s[sc++] = 'R', y--;
		}
	}
	for (i = sc - 1; i >= 0; i--)
		printf("%c", s[i]);

	return 0;
}





// lang: GNU C++
// memory: 21200 KB
// author: imslavko
// submit_date: Jan 27, 2011 6:27:01 AM
// contest: 2
// link: /contest/2/submission/266005
// time: 470 ms
// verdict: Accepted
// problem: 2B - The least round way
// ID: 266005
// downloaded by very stupid script
