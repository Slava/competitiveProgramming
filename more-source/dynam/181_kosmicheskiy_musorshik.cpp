// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

// 0 - N
// 1 - S
// 2 - W
// 3 - E
// 4 - U
// 5 - D

long a[6][200], b[6][200], n;
char s[200], c;

int r (char t)
{
    if (t == 'N')
        return 0;
    if (t == 'S')
        return 1;
    if (t == 'W')
        return 2;
    if (t == 'E')
        return 3;
    if (t == 'U')
        return 4;
    if (t == 'D')
        return 5;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    for (int i = 0; i < 6; i++)
    {
        gets (s);
        b[i][0] = strlen (s);
        for (int j = 0; j < b[i][0]; j++)
            b[i][j + 1] = r(s[j]);
        a[i][0] = 1;
    }

    scanf ("%c %d", &c, &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
        {
            a[j][i] = 1;
            for (int k = 1; k <= b[j][0]; k++)
                a[j][i] += a[b[j][k]][i - 1];
        }

    printf ("%ld\n", a[r(c)][n - 1]);

    return 0;
}
