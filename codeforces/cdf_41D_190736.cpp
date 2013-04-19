#include <cstdio>
#define max(a,b) (a>b?a:b)

int n, m, k, a[200][200], d[200][200][12], ans[200], t, s, p;
char S[200];

int main()
{
    scanf ("%d%d%d", &n, &m, &k);
    k++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int l = 0; l < 12; l++)
                d[i][j][l] = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        scanf ("%s", S);
        for (int j = 0; j < m; j++)
            a[i][j] = S[j] - '0';
    }
    for (int i = 0; i < m; i++)
        d[0][i][a[0][i] % k] = a[0][i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int l = 0; l < k; l++)
            {
                if (j != m - 1 && d[i - 1][j + 1][l] != -1)
                    d[i][j][(d[i - 1][j + 1][l] + a[i][j]) % k] =
                        max (d[i][j][(d[i - 1][j + 1][l] + a[i][j]) % k],
                            d[i - 1][j + 1][l] + a[i][j]);
                if (j && d[i - 1][j - 1][l] != -1)
                    d[i][j][(d[i - 1][j - 1][l] + a[i][j]) % k] =
                        max (d[i][j][(d[i - 1][j - 1][l] + a[i][j]) % k],
                             d[i - 1][j - 1][l] + a[i][j]);
            }

    for (int i = 0; i < m; i++)
        if (d[n - 1][s][0] < d[n - 1][i][0])
            s = i;

    printf ("%d\n", d[n - 1][s][0]);

    if (d[n - 1][s][0] == -1)
        return 0;

    for (int i = n - 1; i > 0; i--)
    {
        if (s != m - 1 && d[i][s][p] - a[i][s] == d[i - 1][s + 1][(d[i][s][p] - a[i][s]) % k])
        {
            p = (d[i][s][p] - a[i][s]) % k;
            s++;
            ans[t++] = 0;
        }
        else
        {
            p = (d[i][s][p] - a[i][s]) % k;
            s--;
            ans[t++] = 1;
        }
    }
    printf ("%d\n", s + 1);
    for (int i = t - 1; i >= 0; i--)
        printf ("%c", ans[i]?'R':'L');


    return 0;
}
/*
5 5 10
43210
98765
02468
13579
12345
*/





// lang: GNU C++
// memory: 3300 KB
// author: imslavko
// submit_date: Dec 1, 2010 6:58:16 AM
// contest: 41
// link: /contest/41/submission/190736
// time: 30 ms
// verdict: Accepted
// problem: 41D - Pawn
// ID: 190736
// downloaded by very stupid script
