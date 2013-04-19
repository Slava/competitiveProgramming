// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>


int main ()
{
    int n, i, j;
    scanf ("%d", &n);
    printf ("%d\n", n / 2 * (n - n / 2));
    for (i = 1; i <= n / 2; i++)
        for (j = n / 2 + 1; j <= n; j++)
            printf ("%d %d\n", i, j);

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 28, 2010 8:32:40 AM
// contest: 41
// link: /contest/41/submission/190648
// time: 30 ms
// verdict: Accepted
// problem: 41E - 3-cycles
// ID: 190648
// downloaded by very stupid script
