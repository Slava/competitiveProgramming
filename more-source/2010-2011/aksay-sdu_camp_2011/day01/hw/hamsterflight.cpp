#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double t, v, k1, k2, PI = acos(-1);
double l, r, ll, rr, eps = 0.000000001;

double f(double x)
{
    return double(sin(x) * sin(x) * v * v * k2 / double(20.0) + sin(2*x) * v * v * k1 / double(10.0));
}

int main ()
{
    cin >> t;
    while (t--)
    {
        scanf ("%lf%lf%lf", &v, &k1, &k2);
        l = 0; r = PI / 2;
        while (r - l >= eps)
        {
            ll = l + (r - l) / 3;
            rr = l + 2 * (r - l) / 3;

            if (f(ll) < f(rr))
                l = ll;
            else r = rr;
        }
        printf ("%.3lf %.3lf\n", l, f(l));
    }


    return 0;
}
