#include <cstdio>

int main ()
{
	long long a, b, c;
	scanf ("%I64d%I64d%I64d", &a, &b, &c);
	printf("%I64d", (a/c + (a%c != 0)) * (b/c + (b%c != 0)));
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 26, 2011 10:41:44 AM
// contest: 1
// link: /contest/1/submission/265349
// time: 30 ms
// verdict: Accepted
// problem: 1A - Theater Square
// ID: 265349
// downloaded by very stupid script
