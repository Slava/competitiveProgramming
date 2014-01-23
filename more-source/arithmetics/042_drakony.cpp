// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cmath>

using namespace std;

#define ll __int64
#define STR "%I64d"

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    ll n, a, b, ans = 1;
    scanf (STR, &n);
    if (n == 1)
    {
        printf ("1");
        return 0;
    }

    a = n / 3;
    n = n % 3;
    if (n % 2 == 1)
    {a--; n += 3;}
    b = n / 2;
    for (int i = 1; i <= a; i++)
        ans *= 3;
    for (int i = 1; i <= b; i++)
        ans *= 2;
    printf (STR, ans);

    return 0;
}
