// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n, a;
    scanf ("%ld", &n);

    for (long i = 25600; i; i--)
    {
        a = i * (i - 1) / 2;
        if (a > n) continue;
        if ((n - a) % i == 0)
        {printf ("%ld", i);break;}
    }


    return 0;
}

