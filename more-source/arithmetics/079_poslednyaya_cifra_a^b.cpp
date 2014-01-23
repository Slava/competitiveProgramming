// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    long a, b, r = 1, i;
    scanf ("%ld%ld", &a, &b);
    for (i = 1; i <= b; i++)
        r = (r * a) % 10;
    printf ("%ld", r);

    return 0;
}

