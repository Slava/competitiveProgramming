// Kim Vyacheslav KarKTL
#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, a[10000], l, r, ans = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    sort (a,a+n);
    if (n == 1) ans = 0;
    else
    {
        for (int i = 0; i < n; i++)
            ans += a[i];
        if (2*a[n-1] - ans > 0)
            ans = ans - a[n-1];
        else ans /= 2;
    }

    printf ("%d ", ans);
    return 0;
}
