#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int a[100001], k, m, i, j, l, n, p = 1;
char s[100001];
main ()
{
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);

    scanf ("%d%d", &k, &m);
    cin >> s;
    l = strlen (s);
    for (i = 0; i < l; i++)
    {
        if (s[i] <= 'Z' && s[i] >= 'A') a[l - i - 1] = s[i] - 55;
        else a[l - i - 1] = s[i] - 48;
    }
    n = a[0] % m;

    for (i = 1; i < l; i++)
    {
        p = (p * (k % m)) % m;
        n = (n + (p * a[i]) % m) % m;
    }
    printf ("%d", n % m);
}
