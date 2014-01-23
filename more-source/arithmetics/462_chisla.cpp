// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n;
    scanf ("%ld", &n);
    n -= n/2 + n/5 + n/3 - n/10 - n/15 - n/6 + n/30;
    printf ("%ld", n);

    return 0;
}
