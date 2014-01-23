// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

int a[13][32], lim[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m, d;

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);

    scanf ("%d%d", &d, &m);
    for (int i = 12; i > 1; i--)
        for (int j = lim[i]; j > 1; j--)
        {
            a[i][j] = 1;
            if (j + 1 <= lim[i]) a[i][j] &= a[i][j + 1];
            if (j + 2 <= lim[i]) a[i][j] &= a[i][j + 2];
            if (i < 12) a[i][j] &= a[i + 1][j];
            if (i < 11) a[i][j] &= a[i + 2][j];

        }

    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= lim[i]; j++)
            printf ("%d ", a[i][j]);
        puts("");
    }

    printf ("%d\n", a[m][d] + 1);

    return 0;
}
