/*
ID: imslavko1
PROG: sym
LANG: C++
*/

#include <cstdio>

using namespace std;

long n, m, ans;

long p (int n, int m)
{
    if (n%2 == 0 || m%2 == 0)
        return 0;
    return 1 + p(n / 2, m / 2) * 4;
}

int main ()
{
    freopen ("sym.in", "r", stdin);
    freopen ("sym.out", "w", stdout);

    scanf ("%ld%ld", &n, &m);
    ans = p(n, m);
    printf ("%ld\n", ans);

    return 0;
}

