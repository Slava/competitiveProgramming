// Kim Vyacheslav KarKTL
#include <cstdio>
#define abs(x) ((x)<0?-(x):(x))
#define ll __int64

ll gcd (ll a, ll b)
{
    while (a && b)
        if (a > b)
            a %= b;
        else b %= a;
    return a + b;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    ll x1, y1, x2, y2, x3, y3, ans = 0;
    scanf ("%I64d%I64d%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2, &x3, &y3);
    ans += gcd (abs (x1-x2), abs(y1-y2));
    ans += gcd (abs (x1-x3), abs(y1-y3));
    ans += gcd (abs (x3-x2), abs(y3-y2));

    printf ("%I64d", ans);

    return 0;
}
