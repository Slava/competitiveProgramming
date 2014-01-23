// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>

using namespace std;

__int64 n, k, i, t, m, c, d, nk, ii;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> n >> k;
    nk = n - k;
    d = k + 1;
    if (!nk)
        m = 1;
    if (nk < 0) m = 0;
    for (i = 2; i * i <= nk; i++)
        if (nk % i == 0)
        {
            // i
            for (t = n, c = 0; t % i == k; c++, t /= i);
            if (m < c)
            {
                m = c;
                d = i;
            }

            // nk / i
            ii = nk / i;
            for (t = n, c = 0; t % ii == k; c++, t /= ii);
            if (m < c)
            {
                m = c;
                d = ii;
            }
        }
    if (!m && n % nk == k)
    {
        d = nk;
        m = 1;
    }

    cout << d << ' ' << m;

    return 0;
}

