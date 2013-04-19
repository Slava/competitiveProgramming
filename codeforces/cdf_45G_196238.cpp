// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

bool np[18003002];
bool pr (long x)
{
    for (int i = 2; i * i <= x; i++)
	if (x % i == 0)
	    return 0;
    return 1;
}
int main ()
{
    long n, a[10000], s;
    scanf ("%ld", &n);
    s = n * (n + 1) / 2;
    for (long i = 1; i <= n; i++)
        a[i] = 1;
    if (!pr(s))
    {
        if (s % 2 == 0)
        {
            for (long i = 3; s - i >= 0; i++)
                if (pr(i) && pr(s - i))
                {
                    a[i] = 2;break;
                }
        }
        else
        {
            if (s > 2 && pr(s - 2))
                a[2] = 2;
            else
            {
                a[3] = 3;
                for (long i = 4; s - 3 - i >= 0; i++)
                    if (pr(i) && pr(s - 3 - i))
                    {
                        a[i] = 2; break;
                    }
            }
        }
    }

    for (long i = 1; i <= n; i++)
        printf ("%ld ", a[i]);

    return 0;
}




// lang: GNU C++
// memory: 18900 KB
// author: imslavko
// submit_date: Nov 26, 2010 6:44:42 AM
// contest: 45
// link: /contest/45/submission/196238
// time: 30 ms
// verdict: Accepted
// problem: 45G - Prime Problem
// ID: 196238
// downloaded by very stupid script
