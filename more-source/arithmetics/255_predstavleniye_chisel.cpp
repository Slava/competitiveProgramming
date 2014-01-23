// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n;
    scanf ("%ld", &n);

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            long a = n / i, b = n - a;
            printf("%ld %ld", a, b);return 0;
        }

    printf("%ld %ld", 1, n - 1);

    return 0;
}
