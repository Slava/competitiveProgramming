// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int a[251][251], n, m;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= 250; i++)
        a[i][i] = a[i][1] = a[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        int j = 2;
        for (; j <= m; j++)
            if (!a[i][j])
                break;
        if (j != m + 1)
        {
            a[i][j] = 2;
            for (int k = j + 1; k <= m; k++)
                a[i][k] = 1;
            for (int k = i + 1; k <= n; k++)
                a[k][j] = 1;
            for (int k = 1; k + i <= n && k + j <= m; k++)
                a[i + k][j + k] = 1;
        }
    }

    printf ("%d\n", a[n][m]);

    return 0;
}

