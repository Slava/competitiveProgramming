// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

bool p[10000000];

void resheto (long n)
{
    for (long i = 2; i <= n; i++)
        if (!p[i])
            for (long j = i + i; j <= n; j += i)
                p[j] = 1;
}

void find (long n)
{
    long i;
    for (i = n + 1; i <= 2 * n; i++)
        if (!p[i])
            break;
    if (i - n > 0)
        for (long j = 0; j < n/2; j++)
            if (i - n + j < n - j) printf ("%ld %ld\n", i - n + j, n - j);
    if (i - n - 1 > 1)
        find (i - n - 1);
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n;
    scanf ("%ld", &n);
    resheto (n * 2);
    find (n);

    return 0;
}
