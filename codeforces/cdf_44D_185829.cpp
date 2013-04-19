// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cmath>

using namespace std;

int n, x[5009], y[5009], z[5009];
double ans = 1234567890;

#define sqr(x) ((x)*(x))
#define min(a,b) ((a<b)?(a):(b))

double d (int i, int j)
{
    return sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j]) + sqr(z[i]-z[j]));
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d%d%d", &x[i], &y[i], &z[i]);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = min (ans, d(0, i) + d(0, j) + d(i, j));

    printf ("%.8lf", ans / 2);

    return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Dec 1, 2010 8:32:28 AM
// contest: 44
// link: /contest/44/submission/185829
// time: 1010 ms
// verdict: Accepted
// problem: 44D - Hyperdrive
// ID: 185829
// downloaded by very stupid script
