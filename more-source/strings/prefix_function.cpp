#include <cstdio>
#include <cstring>

char s[1010100];
int n, p[1010100], r;
void solve ()
{
	scanf ("%d\n%s", &n, s);
	memset(p, 0, sizeof p);
	for (int i = 1; i < n; i++)
	{
		p[i] = p[i - 1];
		while (p[i] > 0 && s[i] != s[p[i]])
			p[i] = p[p[i] - 1];
		if (s[i] == s[p[i]])
			p[i]++;
		r = i - p[i] + 1;
		if ((i + 1) % r == 0 && (i + 1) / r > 1)
			printf("%d %d\n", i + 1, (i + 1) / r);
	}
	puts("");
}

int main ()
{
	int m;
	scanf ("%d", &m);
	for (int i = 1; i <= m; i++)
		printf("Test case #%d\n", i),
		solve();
	return 0;
}

