#include <cstdio>

char m[9][9];
int ans, b;
int main ()
{
	for (int i = 0; i < 8; i++)
	{
		gets(m[i]);
		b = 1;
		for (int j = 0; j < 8; j++)
			if (m[i][j] == 'W')
				b = 0;
		ans += b;
	}
	for (int j = 0; j < 8; j++)
	{
		b = 1;
		for (int i = 0; i < 8; i++)
			if (m[i][j] == 'W')
				b = 0;
		ans += b;
	}
	if (ans == 16)
		ans = 8;
	printf("%d", ans);
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Mar 1, 2011 10:51:26 AM
// contest: 7
// link: /contest/7/submission/313060
// time: 30 ms
// verdict: Accepted
// problem: 7A - Kalevitch and Chess
// ID: 313060
// downloaded by very stupid script
