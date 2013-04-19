#include <cstdio>

char s[200], c[200];
main ()
{
	scanf ("%s\n%s", s, c);
	for (int i = 0; s[i] != '\0'; i++)
		printf("%d", s[i] != c[i]);
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 23, 2011 8:25:44 AM
// contest: 61
// link: /contest/61/submission/300030
// time: 30 ms
// verdict: Accepted
// problem: 61A - Ultra-Fast Mathematician
// ID: 300030
// downloaded by very stupid script
