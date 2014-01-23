// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cmath>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    double x1, x2, y1, y2;
    scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    printf ("%lf", sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));

    return 0;
}
