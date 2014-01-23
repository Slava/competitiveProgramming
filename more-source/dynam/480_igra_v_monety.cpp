// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#define max(a,b) (a<b?b:a)

long n, k, d[1890][890], a[1890], s[1890], c[890];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &n);
    for (int i = 0; i < n; i++)
        scanf ("%ld", &a[i]);
    scanf ("%ld", &k);

    for (int i = n - 1; i >= 0; i--)
        s[i] = s[i + 1] + a[i];
    if (k >= n)
    {
        printf ("%ld", s[n - 1]);
        return 0;
    }
    for (int i = 1; i <= k; i++)
        d[n - 1][i] = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= k; j++)
        {
            c[i] = max (c[i], s[i] - d[i + j][j]);
            d[i][j] = c[i];
        }
    }
    printf ("%ld", d[0][k]);

    return 0;
}

