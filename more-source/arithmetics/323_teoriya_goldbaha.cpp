// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

bool prime (int a)
{
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return 0;
    return 1;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n;
    scanf ("%d", &n);

    for (int i = 2; i < n; i++)
        if (prime (i) & prime (n-i))
        {
            printf ("%d %d", i, n - i);
            return 0;
        }

    return 0;
}
