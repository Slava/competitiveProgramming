// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cmath>

using namespace std;

long a[100000], b[100000], c[100000], n, div, i, l = 0, t = 1;
int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &n);

    for (i = 2; i <= n; i++)
    {
        if (i * i > n) i = n;
        div = 0;
        while (n % i == 0)
        {
            div++;
            n /= i;
        }
        if (!div) continue;
        a[l] = i;
        b[l] = div;
        c[l] = 1;
        t *= i;
        l++;
    }

    for (i = 0; i < l; i++)
        while (t * c[i] < b[i])
        {
            t *= a[i];
            c[i]++;
        }

    printf ("%ld", t);

    return 0;
}
