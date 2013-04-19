// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

#define max(a,b) (a>b?a:b)

int main ()
{
    int n, m, a[3000], ans;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    ans = m;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                ans = max (ans, (m / a[j] * a[i]) + (m % a[j]));
    printf ("%d", ans);

    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 26, 2010 7:24:46 AM
// contest: 41
// link: /contest/41/submission/190613
// time: 50 ms
// verdict: Accepted
// problem: 41B - Martian Dollar
// ID: 190613
// downloaded by very stupid script
