#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define __int64 long long
__int64 a[20], n, k;
int i, j;

__int64 f(int n)
{
    __int64 r = 1;
    for (int i = 2; i <= n; i++)
        r *= i;
    return r;
}
main ()
{
    freopen ("binom.in", "r", stdin);
    freopen ("binom.out", "w", stdout);
    cin >> n >> k;
    a[0] = 1;
    if (n > 0)
    {
        for(i = 1; i <= n; i++)
        {
            for (j = k; j > 0; j--)
            {
                a[j] += a[j - 1];
            }
        }
        cout << a[k];
    }
    else
    {
        __int64 r = 1;
        for (i = 0; i < k; i++)
        {
            r *= n - i;
        }
        cout << r / f(k);
    }
}
