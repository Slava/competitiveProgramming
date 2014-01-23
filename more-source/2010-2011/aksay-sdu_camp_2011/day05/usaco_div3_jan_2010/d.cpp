/*
ID: imslavko1
PROG: cropcir
LANG: C++
*/

#include <cstdio>
#include <cmath>

using namespace std;

#define sqr(x) ((x)*(x))

struct cir
{
    double x, y, r;
}a[10009];

bool inter(cir a, cir b)
{
    return
    sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)) < a.r + b.r;
}

int ans[10009];

int main ()
{
  freopen ("cropcir.in", "r", stdin);
  freopen ("cropcir.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (inter(a[i], a[j]))
            {
                ans[i]++;ans[j]++;
            }

    for (int i = 0; i < n; i++)
        printf ("%d\n", ans[i]);

    return 0;
}

