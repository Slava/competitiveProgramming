#include <cstdio>
using namespace std;
int a[201], l, n, i, j;

int mix (int n, int i)
{
    while (i < n && a[i]) a[i] = 0, i++;
    a[i]++;
    for (j = 0; j < n; j++)
        if (a[j])
            printf ("%d ", j + 1);
    printf ("\n");

    return i;
}
main ()
{
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);

    scanf ("%d", &n);
    mix (n, 0);

    while (i < n) i = mix (n, 0);
}
