#include <cstdio>

char s[200], c[200];
main ()
{
	scanf ("%s\n%s", s, c);
	for (int i = 0; s[i] != '\0'; i++)
		printf("%d", s[i] != c[i]);
}

