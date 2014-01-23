#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double fact[3009999], a;
int t, l, r, m;

int main ()
{
    for (int i = 1; i <= 3000999; i++)
        fact[i] = fact[i - 1] + log(i);
    cin >> t;
    while (t--)
    {
        scanf ("%lf", &a);
        l = -1;
        r = 3000999;
        while (r - l > 0)
        {
            m = (r + l) / 2;
            if (l == m && fact[m] <= log(a) * m)
                break;
            if (fact[m] <= log(a) * m)
                l = m;
            else r = m;
        }
        printf ("%d\n", r);
    }


    return 0;
}

