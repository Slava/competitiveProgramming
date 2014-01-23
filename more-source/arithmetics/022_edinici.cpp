// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long a, s = 0;
    scanf ("%ld", &a);
    for (; a; a >>= 1)
        s += a&1;
    printf ("%ld", s);

    return 0;
}

