#include <cstdio>
#include <cstring>

char s[10100];
int n, r, l, i;
int main ()
{
	freopen ("next.in", "r", stdin);
	freopen ("next.out", "w", stdout);
	scanf ("%s", s);
	n = strlen(s);
	for (r = n - 1; s[r] == '1'; r--);
	s[r] = '1';
	l = r + 1;
	for(;l != n;){
		for (; l + i < n; i++)
			s[l + i] = s[i];
		for (i = n - 1; i >= 0 && ++s[i] == '2'; i--)
			s[i] = '0';
		for (l = n; l - 1 >= 0 && s[l - 1] == '0'; l--);
	}
	for (i = 0; i < n; i++)
		printf("%c", s[i]);
	return 0;
}

