// The equation

#include <cstdio>
#include <iostream>

using namespace std;

int gcd (int a, int b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else b %= a;
    }
    return a + b;
}

int main ()
{
    int a,b,c,X1,X2,Y1,Y2,d;
    cin >> a >> b >> c >> X1 >> X2 >> Y1 >> Y2;
    c = -c;
    d = gcd (a, b);

    if (c % d != 0)
    {
        cout << "0";
        return 0;
    }

    a /= d, b /= d, c /= d;

    int a1 = a,
        b1 = b,
        x1 = 1, y1 = 0,
        x2 = 0, y2 = 1;

    while (a1 && b1)
    {
        if (a1 > b1)
        {
            int coef = a1 / b1;
            a1 -= coef * b1;
            x1 -= coef * x2;
            y1 -= coef * y2;
        }
        else
        {
            int coef = b1 / a1;
            b1 -= coef * a1;
            x2 -= coef * x1;
            y2 -= coef * y1;
        }
    }

    int x, y;
    if (a1 == 1)
    {
        x = x1;
        y = y1;
    }
    else
    {
        x = x2;
        y = y2;
    }

//  ax + by = c
//  a(x + tb) + b(y - ta) = c
    if (X1 > X2) swap (X1, X2);
    if (Y1 > Y2) swap (Y1, Y2);
    int t1, t2, k1, k2;

    cout << max (k2, t2) - min(t1, k1) + 1;

    return 0;
}

/*
sample:
1 1 -3
0 4
0 4

*/

