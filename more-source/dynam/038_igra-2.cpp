// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#define min(a,b) (a<b?a:b)

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, a[109], d[109][109], s;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &a[i]);
        d[i][i] = a[i];
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            if (i == j) s = a[i];
            else
            {
                s += a[j];
                d[i][j] = s - min (d[i + 1][j], d[i][j - 1]);
            }
    if (d[0][n - 1] > s - d[0][n - 1])  printf ("1");
    else if (d[0][n - 1] < s - d[0][n - 1]) printf ("2");
    else printf ("0");

    return 0;
}

