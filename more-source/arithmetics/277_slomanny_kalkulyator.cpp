// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define fail printf("-1"),exit(0);

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long a, n, div[100000], l = 0, ans = 0;
    scanf ("%ld%ld", &a, &n);
    if ((a < 0 && n > 0) || (a > 0 && n < 0))
        fail

    a = abs (a);
    n = abs (n);

    if (a == n)
    {
        printf ("0");
        return 0;
    }

    if (!a || !n)
        fail

    if (n % a > 0) fail
    n /= a;

    for (int i = 2; i <= n; i++)
    {
        if (i * i > n)
            i = n;
        while (n % i == 0)
        {
            ans += i;
            n /= i;
        }
    }

    printf ("%ld", ans);

    return 0;
}

