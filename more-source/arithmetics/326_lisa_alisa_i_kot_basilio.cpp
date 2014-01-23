// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int n, i, j;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);
    i = n / 5;
    n -= i * 5;
    if (n%3 == 1)
    {
        i--;
        n += 5;
    }
    if (n%3 == 2)
    {
        i -= 2;
        n += 10;
    }
    j = n / 3;
    printf ("%d %d", i, j);

    return 0;
}

