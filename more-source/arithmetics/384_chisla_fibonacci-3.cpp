// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

#define ll __int64
ll A = 1, B = 0, T;

ll gcd (ll a, ll b) {
	return b ? gcd (b, a % b) : a;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    ll n, k;
    scanf ("%I64d%I64d", &n, &k);

    for (ll i = 2; i <= gcd(n,k); i++)
    {
        B += A;
        B = B % 1000000000;
        T = A; A = B; B = T;
    }

    printf ("%I64d", A % 1000000000);

    return 0;
}
