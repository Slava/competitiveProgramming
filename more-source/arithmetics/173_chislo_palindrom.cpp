// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

long n, ans;
bool u[39];
char a[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", s[100000000];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &n);
    for (int i = 2; i < 37; i++)
    {
        long l = 0, b = n;

        for (; b; b /= i)
            s[l++] = a[b%i];
        bool t = 1;
        for (long j = 0; j < l; j++)
            if (s[j] != s[l - j - 1])
            {
                t = 0;
                break;
            }
        if(t) u[i] = 1;
    }

    for (int i = 0; i < 37; i++)
        ans += u[i];
    if (!ans) puts("none");
    if (ans == 1) puts("unique");
    if (ans > 1) puts("multiple");

    for (int i = 0; i < 37; i++)
        if (u[i]) printf ("%d ", i);

    return 0;
}
