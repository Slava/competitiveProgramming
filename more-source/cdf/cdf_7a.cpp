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

