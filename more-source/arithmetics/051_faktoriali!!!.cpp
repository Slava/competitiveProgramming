// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, a = 1, i, k = 0;
    char s[25];
    scanf ("%d %s", &n, &s);
    while (s[k]) k++;

    i = n % k;
    if (!i) i = k;

    for (; i <= n; i += k)
        a *= i;
    printf ("%d", a);

    return 0;
}
