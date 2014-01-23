// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

#define ll __int64
#define STR "%I64d"

bool prime (ll a)
{
    for (ll i = 2; i * i <= a; i++)
        if (a % i == 0) return 0;
    return 1;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    ll n;
    scanf (STR, &n);

    while (n)
    {
        if (prime (n))break;
        if (n < 10 && !prime(n))n = 0;
        else
        {
            ll t;
            for (t = 0; n; n /= 10) t += n % 10;
            n = t;
        }
    }

    if (n == 1) n = 0;
    printf (STR, n);

    return 0;
}
