// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

long a[100] = {0, 1}, i, b;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &b);
    if (b == 1)
    {
        printf ("1\n1\n");
        return 0;
    }
    for (i = 2; (a[i] = a[i - 1] + a[i - 2]) <= b; i++)
        if (a[i] == b)
        {
            printf ("1\n%ld\n", i);
            return 0;
        }
    puts ("0");

    return 0;
}

