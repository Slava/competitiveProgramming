#include <cstdio>

int a[255], mn = 'a';
char s[60];
int main ()
{
	scanf ("%s", s);
	for (int i = 0; s[i]; i++)
		a[s[i]]++;
	for (int i = 0; i < 255; i++)
		if (a[i] > a[mn]) mn = i;
	printf("%c", mn);
	return 0;
}

