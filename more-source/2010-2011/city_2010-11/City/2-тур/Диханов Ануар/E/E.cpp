#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1001][1001], b[1001][1001], n, m, i, j, k, s;
char c;

main ()
{
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '0')a[i][j] = 1000001;
            else a[i][j] = c - 48;
        }

    for (i = n - 1; i >= 0; i--)
        for (j = 0; j < m; j++)
        {
            if (i == n - 1 && j)
                if (a[i][j]) a[i][j] += a[i][j - 1];

            if (j == 0 && i != n - 1)
                if (a[i][j]) a[i][j] += a[i + 1][j];

            if (i != n - 1 && j)
                a[i][j] += min (a[i + 1][j], a[i][j - 1]);
        }

    b[n - 1][0] = 1;
    if (a[0][m - 1] != m + n - 1) printf ("impossible"), exit (0);
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < m; j++)
        {
            if (b[i][j])
            {
                if (i != 0 && j < m - 1)
                {
                    if (a[i][j + 1] - 1 == a[i][j])
                        b[i][j + 1] += b[i][j];
                    if (a[i - 1][j] - 1 == a[i][j])
                        b[i - 1][j] += b[i][j];
                }
                if (i == 0 && j < m - 1 && a[i][j + 1] - 1 == a[i][j])
                {
                    b[i][j + 1] += b[i][j];
                }
                if (j == m - 1 && i != 0 && a[i - 1][j] - 1 == a[i][j])
                {
                    b[i - 1][j] += b[i][j];
                }
            }
        }
    }

    printf ("%d", b[0][m - 1]);
}
