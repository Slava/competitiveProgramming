// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long a, b, x, y, c, A[10], n = 0, d[10] = {0};
    scanf ("%ld%ld%ld", &a, &b, &c);

    x = a;
    while (x)
    {
        A[n++] = (x%10);
        x /= 10;
    }

    sort (A, A + n);

    do
    {
        x = 0;
        for (int i = 0; i < n; i++)
            x += A[i] * pow (10, n-i-1);
        y = c - x;
        for (int i = 0; i < 10; i++)
            d[i] = 0;
        while (y)
        {
            d[y%10]++;
            y /= 10;
        }
        y = b;
        while (y)
        {
            d[y%10]--;
            y /= 10;
        }
        bool t = 1;

        for (int i = 0; i < 10; i++)
            if (d[i]) {t = 0; break;}
        if (t)
        {
            puts("YES");
            y = c - x;
            printf ("%ld %ld", x, y);
            return 0;
        }
    } while (next_permutation(A, A + n));

    puts ("NO");

    return 0;
}

