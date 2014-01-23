#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

main ()
{
    freopen ("dragon.in", "r", stdin);
    freopen ("dragon.out", "w", stdout);

    long n, d;
    scanf ("%ld%ld", &n, &d);
    if (d > pow (10.0, n + .0) - 1)
        puts ("No solution");
    else
    {
        printf ("%ld", d);
        long r = 9, s = 1;
        while (r < d)
        {
            r = r * 10 + 9;
            s++;
        }
        for (int i = 0; i < (n-s); i++)
            cout << 0;

    }

    return 0;
}

