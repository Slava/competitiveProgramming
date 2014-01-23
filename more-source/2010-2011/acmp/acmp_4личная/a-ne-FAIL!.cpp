#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long a, s = 0;
    scanf ("%ld", &a);
    while (a)
    {
        s += (a & 1);
        a = a >> 1;
    }
    printf("%ld", s);


    return 0;
}
