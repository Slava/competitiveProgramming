// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, a, max, t;
    scanf ("%d", &a);
    max = a;

    for (n = 0; a; a >>= 1) n++;
    a = max;
    for (int i = 0; i < n; i++)
    {
        t = 1 & a;
        a >>= 1;
        a = a | (t << (n - 1));
        if (a > max)
            max = a;
    }

    printf ("%d", max);

    return 0;
}
