// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cmath>

using namespace std;

__int64 n, ans = 1, a, i = 2;


int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%I64d", &n);

    a = 0;
    while (i <= n)
    {
        if ((n % i) == 0)
        {
            n /= i;
            a++;
        }
        else
        {
            i++;
            if (a) ans = ans * a;
            a = 0;
        }
    }
    if (a) ans = ans * a;
    printf("%I64d", ans);

    return 0;
}

