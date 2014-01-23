// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

bool check (long a)
{
    long z = 1;
    for (long b = a; b; b /= 10)
        z *= (b%10);
    return (z && a%z == 0);
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long l, r, ans = 0;
    scanf ("%ld%ld", &l, &r);

    for (; l  <= r; l++)
        if (check(l))
            ans++;
    printf ("%ld", ans);

    return 0;
}
