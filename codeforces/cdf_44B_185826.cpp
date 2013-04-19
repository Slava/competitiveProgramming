// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int main ()
{
    long a, b, c, n, ans = 0;
    scanf ("%ld%ld%ld%ld", &n, &a, &b, &c);
    n *= 2;
    for (int i = 0; i <= c * 4; i += 4)
        for (int j = 0; j <= b * 2; j += 2)
            if ( i + j <= n && n - i - j <= a)
                ans++;

    printf ("%ld", ans);

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 1, 2010 7:32:49 AM
// contest: 44
// link: /contest/44/submission/185826
// time: 50 ms
// verdict: Accepted
// problem: 44B - Cola
// ID: 185826
// downloaded by very stupid script
