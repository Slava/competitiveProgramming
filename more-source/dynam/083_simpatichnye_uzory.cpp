// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

#define bit(x,z) ((x>>z)&1)

long n, m, ans, a[31][1 << 6];
bool msk[1 << 6][1 << 6];

bool can (long a, long b)
{
    for (long i = 1; i < m; i++)
        if (bit(a,i) == bit(a,i - 1) && bit(b,i) == bit(b,i - 1)
            && bit(a,i) == bit(b,i))
            return false;
    return true;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld%ld", &n, &m);
    if (n < m) { long t = m; m = n; n = t; }

    for (long i = 0; i < (1 << m); i++)
        a[1][i] = 1;
    for (long i = 0; i < (1 << m); i++)
        for (long j = 0; j < (1 << m); j++)
            msk[i][j] = can(i,j);

    for (long i = 2; i <= n; i++)
        for (long mask = 0; mask < (1 << m); mask++)
            for (long tmask = 0; tmask < (1 << m); tmask++)
                if (msk[mask][tmask])
                    a[i][mask] += a[i - 1][tmask];
    for (long i = 0; i < (1 << m); i++)
        ans += a[n][i];

    printf ("%ld", ans);

    return 0;
}

