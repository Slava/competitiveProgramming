/*
ID: imslavko1
PROG: profits
LANG: C++
*/
#include <cstdio>

const int N = 101000;
long n, a[N], b[N], mx, i;
#define max(a,b) ((a)>(b)?(a):(b))
int main ()
{
	freopen ("profits.in", "r", stdin);
	freopen ("profits.out", "w", stdout);

	scanf ("%ld", &n);
	for (i = 0; i < n; i++)
		scanf ("%ld", a + i);
	mx = b[0] = a[0];
	for (i = 1; i < n; i++)
		b[i] = max(a[i], a[i] + b[i - 1]);
	for (i = 1; i < n; i++)
		mx = max(mx, b[i]);
	printf("%ld\n", mx);
	return 0;
}
