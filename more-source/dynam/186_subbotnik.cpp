// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[1009], b[1009], c[1009];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    sort (a, a + n);

    b[1] = a[1] - a[0];
    b[2] = a[2] - a[0];
    c[1] = b[1];
    c[2] = b[2];

    for (int i = 3; i < n; i++)
        if (max (c[i - 2], a[i] - a[i - 1]) < b[i - 1] + a[i] - a[i - 1])
        {
            c[i] = max (c[i - 2], a[i] - a[i - 1]);
            b[i] = a[i] - a[i - 1];
        }
        else
        {
            b[i] = b[i - 1] + a[i] - a[i - 1];
            c[i] = max (c[i - 1], b[i]);
        }
    printf ("%d", c[n - 1]);

    return 0;
}

