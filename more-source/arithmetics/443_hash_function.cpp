// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

char s[200];
long x, m, l, P[2009], ans;

long p ()
{
    l = strlen (s);
    long X = 1, r = 0;
    for (int i = 0; i < l; i++, X = (x * X) % m)
        r = (r + (((s[i] - '0') % m) * (X % m) % m)) % m;
    return r;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n;
    scanf ("%d%ld%ld", &n, &m, &x);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", s);
        P[p()]++;
    }

    for (int i = 0; i < m; i++)
    {
        ans += (P[i] * (P[i] - 1)) / 2;
    }

    printf ("%ld", ans);

    return 0;
}
