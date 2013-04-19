#include <cstdio>
#include <cstring>

char s[20000];
int bin = 1, n;
int main ()
{
	freopen ("kiss.in", "r", stdin);
	freopen ("kiss.out", "w", stdout);
	scanf ("%s", s);n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] != '0' && s[i] != '1')
			bin = 0;
	if (bin)
		puts("Yakshi!");
	else puts("Yok :(");
}

