// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>

using namespace std;

char s[30];
__int64 n, a[30], b[30], c[30], p = 0, ans = 0, t;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%s", s);
    n = strlen (s);

    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    p = a[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = p;
        p *= 10;
        p += a[i];
    }

    p = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        c[i] = c[i + 1] + a[i + 1] * p;
        p *= 10;
    }

    p = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += p * b[i];
        if (a[i] == 5) ans += c[i] + 1;
        if (a[i] > 5) ans += p;
        p *= 10;
    }

    printf ("%I64d", ans);

    return 0;
}

