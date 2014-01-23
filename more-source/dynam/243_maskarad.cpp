#include <cstdio>
#define forn(i,n) for(int i = 0; i < n; i++)
#define min(a,b) (a<b?a:b)

const int NN = 1090;
long a[NN][NN * 2], n, l, m,
     p[NN], r[NN], q[NN], f[NN],
     fmax, inf = 1 << 30, ans = 1 << 30;

int cost (int k, int i)
{
    if (k > f[i])
        return inf;
    if (k >= r[i])
        return q[i] * k;
    return p[i] * k;
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    scanf("%ld%ld", &n, &l);
    forn(i,n)
    {
        scanf ("%ld%ld%ld%ld", p+i, r+i, q+i, f+i);
        if (f[i] > fmax)
            fmax = f[i];
    }
    m = l + fmax;
    forn(j,m + 1)forn(i,n)
        a[i][j] = inf;
    forn(i,m + 1)
        a[0][i] = cost(i, 0);
    forn(j,m + 1)for (int i = 1; i < n; i++)
        forn(k, min(j, f[i]) + 1)
            a[i][j] = min(a[i][j], a[i - 1][j - k] + cost(k, i));

    for (int i = l; i <= m; i++)
        ans = min (ans, a[n - 1][i]);

    if (ans != inf)
        printf("%ld", ans);
    else puts("-1");

    return 0;
}
