// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int check (int a)
{
    int b, c;
    c = a;
    for (b = 0; c; c /= 10)
    {
        b *= 10;
        b += c%10;
    }
    return a + b;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);


    int k, ans = 0;
    scanf ("%d", &k);
    for (int i = 1; i <= 1000000; i++)
        if (check(i) == k)
            ans++;

    printf ("%d", ans);

    return 0;
}
