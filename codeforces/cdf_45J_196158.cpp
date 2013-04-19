// Kim Vyacheslav KarKTL
#include <cstdio>

int a[109][109], n, m, x, y;

int main ()
{
    scanf ("%d%d", &n, &m);
    if (n == 1 && m == 1)
    {
        puts ("1");
        return 0;
    }
    if ((n == 1 && m <= 3) || (n <= 3 && m == 1) || (n == 2 && m == 2))
    {
        puts("-1");
        return 0;
    }
    int k = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i+j)%2) a[i][j] = k++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!a[i][j]) a[i][j] = k++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf ("%d ", a[i][j]);
        puts("");
    }

    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 24, 2010 10:37:34 AM
// contest: 45
// link: /contest/45/submission/196158
// time: 30 ms
// verdict: Accepted
// problem: 45J - Planting Trees
// ID: 196158
// downloaded by very stupid script
