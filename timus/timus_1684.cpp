#include <cstdio>
#include <cstring>

const int N = 200000;
int n, pi[N], i, j, a = 1, started, start;
int ans[N];
char s[N], t[N];
int main ()
{
	scanf("%s%s", s, t);
	strcat(s, "$"); strcat(s, t);
	n = strlen(s);
	for (i = 1; i < n; i++)
	{
		j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		pi[i] = j + (s[i] == s[j]);
		if (started)
			a &= !!pi[i];
		if (s[i] == '$')
			started = 1, start = i + 1;
	}
	if (a)
	{
		puts("No");
		for (i = n - 1; i >= start; )
		{
			ans[i] = 1;
			i -= pi[i];
		}
		for (i = start; i < n; i++)
		{
			printf("%c", s[i]);
			if (ans[i])
				printf(" ");
		}
	}
	else puts("Yes");
	return 0;
}

