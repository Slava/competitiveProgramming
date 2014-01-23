// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long a, k, sum = 0, mul = 1;
    scanf ("%ld%ld", &a, &k);

    while (a)
    {
        sum += a%k;
        mul *= a%k;
        a /= k;
    }
    printf ("%ld", mul - sum);

    return 0;
}

