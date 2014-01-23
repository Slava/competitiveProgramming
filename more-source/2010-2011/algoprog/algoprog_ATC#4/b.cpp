// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <set>

using namespace std;

#define file "business"

long long n, m, u[3000], d[3000], MIN = 1000000000000000;

long long D(long long a, long long b)
{
    long i, j;
    for (i = 0, j = n; ; i++, j--)
        if (a * i > b * j)
            return a * i - b * j;
}

int main ()
{
    freopen (file".in", "r", stdin);
    freopen (file".out", "w", stdout);

    scanf ("%lld%lld", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf ("%lld%lld", &u[i], &d[i]);
        MIN = min (MIN, D(u[i],d[i]));
    }

    printf ("%lld\n", MIN);

    return 0;
}
