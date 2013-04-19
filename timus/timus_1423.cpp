#include <cstdio>
#include <cstring>

const int N = 750100;
int n, pi[N], j, i, k, ts;
char s[N], t[N];
int main ()
{
	scanf ("%d%s%s", &k, t, s);
	strcat(s, "$");strcat(s, t);strcat(s, t);
	n = k * 3 + 1;
	for (int i = 1; i < n; i++)
	{
		ts = pi[i - 1];
		while (ts > 0 && s[ts] != s[i])
			ts = pi[ts - 1];
		pi[i] = ts;
		if (s[i] == s[ts])
			pi[i]++;
	}
	for (int i = n - 1; i >= 0; i--)
		if (pi[i] == k)
		{
			j = i;
			break;
		}
	if (j)
		printf("%d", n - j - 1);
	else printf("-1");
	return 0;
}

