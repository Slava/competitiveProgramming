// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int n, m, d[200], a, b;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf ("%d%d", &a, &b);
        for (int j = a; j <= b; j++)
            d[j]++;
    }

    for (int i = 1; i <= n; i++)
        if (d[i] != 1)
        {
            printf ("%d %d\n", i, d[i]);
            return 0;
        }

    puts ("OK");

    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 1, 2010 7:41:05 AM
// contest: 44
// link: /contest/44/submission/185827
// time: 30 ms
// verdict: Accepted
// problem: 44C - Holidays
// ID: 185827
// downloaded by very stupid script
