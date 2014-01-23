#include <cstdio>
#include <cstring>

const int N = 100000;
char s[N], ch;
int au[N][27], n, pi[N], f, pr, ans;
void solve ()
{
	scanf ("%s\n", s);
	strcat(s, "$");
	for (int i = 1; i <= n; i++)
	{
		pi[i] = pi[i - 1];
		while (pi[i] > 0 && s[i] != s[pi[i]])
			pi[i] = pi[pi[i] - 1];
		if (s[i] == s[pi[i]])
			pi[i]++;
	}
	for (int i = 0; i <= n; i++)
		for (int c = 0; c < 26; c++)
			if (i > 0 && c != s[i] - 'a')
				au[i][c] = au[pi[i - 1]][c];
			else 
				au[i][c] = i + (c == s[i] - 'a');
	ans = 0;
	while ((ch = getchar()) != '\n')
	{
		f = au[pr][ch - 'a'];
		if (f == n && ans - n + 1 >= 0)
			printf("%d\n", ans - n + 1);
		pr = f;
		ans++;
	}
	puts("");
}

int main ()
{
	while(scanf("%d\n", &n) == 1)
		solve();
	return 0;
}

