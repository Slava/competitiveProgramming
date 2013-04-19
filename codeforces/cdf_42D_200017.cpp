// Kim Vyacheslav KarKTL
#include <cstdio>

bool u[1001];
int n, a[21];

int main ()
{
    scanf ("%d", &n);

    a[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (a[i] = a[i - 1] + 1;; a[i]++)
        {
            bool flag = 0;
            for (int j = 1; j < i; j++)
                if (u[a[i] + a[j]])
                {
                    flag = 1;
                    break;
                }
            if (!flag)  break;
        }
        for (int j = 1; j < i; j++)
            u[a[i] + a[j]] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf ("%d ", i == j?0:a[i] + a[j]);
        putchar ('\n');
    }

    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 23, 2010 1:39:23 PM
// contest: 42
// link: /contest/42/submission/200017
// time: 30 ms
// verdict: Accepted
// problem: 42D - Strange town
// ID: 200017
// downloaded by very stupid script
