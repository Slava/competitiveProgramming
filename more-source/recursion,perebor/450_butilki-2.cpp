// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>

using namespace std;

long n, a[10][10], b[10][10], ans[10], an = 0;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%ld", &a[i][j]);
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
            s += a[j][i];
        for (int j = 0; j < n; j++)
            b[j][i] = s - a[j][i];
    }

    for (int i = 0; i < n; i++)
        ans [i] = i;

    long j = 0, s = 99999999, t;
    do
    {
        t = 0;
        for (int i = 0; i < n; i++)
            t += b[i][ans[i]];
        if (t < s)
        {
            s = t;
            an = j;
        }
    j++;
    } while (next_permutation (ans, ans + n));

    sort (ans, ans + n);
    for (int i = 0; i < an; i++)
        next_permutation (ans, ans + n);

    for (int i = 0; i < n; i++)
        printf ("%c", ans[i] + 'A');
    printf ("\n");
    printf ("%ld", s);

    return 0;
}

