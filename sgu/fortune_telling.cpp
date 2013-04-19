#include <cstdio>

int n, m;
char s[110][110];
int main ()
{
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf ("%s", s[i]);
	n %= m;
	if (!n)
		n = m;
	printf("%s", s[n]);
}

