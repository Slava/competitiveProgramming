// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n, l = 0, a[] = {9, 8, 7, 6, 5, 4, 3, 2}, s[100000];
    scanf ("%ld", &n);

    if (!n)
        puts ("10");

    while (n > 1)
    {
        bool p = 0;
        for (int i = 0; i < 8; i++)
            if (n % a[i] == 0)
            {
                s[l++] = a[i];
                p = 1;
                n /= a[i];
                break;
            }
        if (!p)
        {
            printf("-1");
            return 0;
        }
    }

    for (int i = l - 1; i >= 0; i--)
        printf ("%d", s[i]);

    return 0;
}
