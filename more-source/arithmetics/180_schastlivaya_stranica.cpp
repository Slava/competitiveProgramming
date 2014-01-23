// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

#define ll __int64

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    ll n, k, q = 0, l = 1;
    scanf ("%I64d%I64d", &n, &k);

    for (ll i = 9; k > 1 && i > 1; i--)
        while (k % i == 0)
        {
            k /= i;
            q += i * l;
            l *= 10;
        }
    if (k == 1 && q <= n)
        printf ("YES");
    else printf ("NO");

    return 0;
}
