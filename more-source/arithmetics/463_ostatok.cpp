// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long m, k, n = 0, r = 1, a[20000];
    char s[200000];
    scanf ("%ld%ld%s", &k, &m, s);

    for (int i = 0; i < strlen (s); i++)
        if (s[i] >= '0' && s[i] <= '9')
            a[strlen(s) - i - 1] = s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            a[strlen(s) - i - 1] = s[i] - 'A' + 10;

    n = a[0] % m;
    for (int i = 1; i < strlen(s); i++)
    {
        r = (r * k) % m;
        n = (n + a[i] * r) % m;
    }

    printf ("%ld", n % m);

    return 0;
}
