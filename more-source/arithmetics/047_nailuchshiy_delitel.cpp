// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int sum (int a)
{
    int r = 0;
    for (; a; a /= 10)
        r += a % 10;
    return r;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, maxsum = 1, min = 1;
    scanf ("%d", &n);

    for (int i = 2; i <= n; i++)
        if (n%i == 0 && sum(i) > maxsum)
        {
            maxsum = sum(i);
            min = i;
        }
    printf ("%d", min);


    return 0;
}
