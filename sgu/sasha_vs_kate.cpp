// 296
#include <cstdio>
#include <cstring>

int k, n, l, i, has[10];
char s[1010];
int main ()
{
	scanf ("%s %d", s, &k);
	n = strlen(s);
	for (k = n - k; k; k--)
	{
		for (i = 0; i < 10; i++)
			has[i] = -1;
		for (i = l; i < n - k + 1; i++)
			if (has[s[i] - 48] == -1)
				has[s[i] - 48] = i;
		for (i = 9; i >= 0; i--)
			if (has[i] != -1)
			{
				printf("%d", i);
				l = has[i] + 1;
				break;
			}
	}
	return 0;
}

