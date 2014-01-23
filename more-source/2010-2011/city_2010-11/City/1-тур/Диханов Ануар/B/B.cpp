#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, i, j, p, a[251][30001], k;

main ()
{
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);

    scanf ("%d%d", &n, &m);

    for(i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf ("%d", &a[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        bool T = 0;
        for (j = 1; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                if (a[j][k] == a[0][i])
                {
                    T = 1;
                    goto next;
                }
            }
            T = 0;
            break;
            next:;
        }
        if (T) printf ("%d", a[0][i]), exit(0);
    }

}
