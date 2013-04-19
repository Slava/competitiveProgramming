#include <cstdio>
#include <cstring>

char s[2000];
int stack[2000];
int cmp (int l1, int r1, int l2, int r2)
{
	while (s[l1] == '0')
		l1++;
	while (s[l2] == '0')
		l2++;
	if (r1 - l1 > r2 - l2)
		return 0;
	if (r2 - l2 > r1 - l1)
		return 1;
	for (; l1 <= r1; l1++, l2++)
		if (s[l1] < s[r1])
			return 1;
		else if (s[l1] > s[r1])
			return 0;
	return 0;
}

int bsearch (int l, int r)
{
	if (l > r)
		return 0;
	int m, L = l, R = r;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (cmp(L, m, m + 1, R))
			l = m + 1;
		else r = m - 1;
	}
	if (!l)
		return 0;
	printf("%d\n", l - 1);
	stack[l - 1] = 1;
	bsearch(l, r);
	return 1;
}

int main ()
{
	freopen ("commas.in", "r", stdin);
	freopen ("commas.out", "w", stdout);

	scanf ("%s", s);
	printf("%d\n", bsearch(0, strlen(s) - 1));
	for (int i = 0; i < strlen(s); i++)
	{
		printf("%c", s[i]);
		if (stack[i])
			printf(",");
	}
	return 0;
}

