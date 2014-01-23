// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

#define min(a, b) (a<b?a:b)

int n;
double c[29], m = 999999999, r, v, a[29], b[29];

int main ()
{
    scanf ("%d%lf", &n, &v);
    for (int i = 0; i < n; i++)
        scanf ("%lf", &a[i]);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lf", &b[i]);
        c[i] = b[i] / a[i];
        m = min (c[i], m);
    }
    for (int i = 0; i < n; i++)
        r += a[i] * m;
    if (r < v) printf ("%.10lf", r);
    else printf ("%lf", v);

    return 0;
}
