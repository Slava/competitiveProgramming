// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

__int64 a[] = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128},
        i, n, m, l = 0, b[9];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf("%I64d%I64d", &m, &n);
    for (i = 0; i < 8; i++)
        if (a[i] >= m && a[i] <= n)
            b[l++] = a[i];
    if (!l) printf ("Absent");
    for (i = 0; i < l; i++)
        printf("%I64d\n", b[i]);

    return 0;
}
