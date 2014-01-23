// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define min(a,b) (a<b?a:b)

long int n, m, a[20], b[20], ans = 999999999, c;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld%ld", &n, &m);
    for (int i = 0; i < m; i++)
        scanf ("%ld", &a[i]);

    sort (a, a + m);
    c = pow (3, m);
    for (int i = 0; i < c; i++)
    {
        long int s = 0, d = 0;
        for (int j = 0; j < m; j++)
            s += a[j] * b[j], d += b[j];
        if (s == n)
            {ans = d;break;}
        if (i == c - 1 && s < n)
            ans = -1;
        int k = m - 1;
        for (; k >= 0; k--)
        {
            b[k]++;
            if (b[k] > 2)
                b[k] = 0;
            else break;
        }

    }

    if (ans == 999999999)
        printf ("0");
    else printf ("%ld", ans);

    return 0;
}
