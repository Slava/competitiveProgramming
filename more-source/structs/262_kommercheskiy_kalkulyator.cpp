// Kim Vyacheslav KarKTL
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100009

double a[MAXN], ans;
int n;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%lf", &a[i]), a[i] = -a[i];
    make_heap (a, a+n);

    while ( n > 1)
    {
        pop_heap (a, a+n);
        pop_heap (a, a+n-1);
        a[n-2] += a[n-1];
        n--;
        ans += a[n-1] * 0.05;
        push_heap (a, a+n);
    }

    printf ("%.2lf", -ans);

    return 0;
}
