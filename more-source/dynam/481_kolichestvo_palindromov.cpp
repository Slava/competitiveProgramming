// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

long a[40][40], n;
char s[40];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%s", s);
    n = strlen (s);


    for (int i = 0; i < n; i++)
        a[i][i] = 1;
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            if (s[i] == s[j])
                a[i][j] = a[i + 1][j] + a[i][j - 1] + 1;
            else a[i][j] = a[i + 1][j] + a[i][j - 1] - a[i + 1][j - 1];
    printf("%ld", a[0][n - 1]);

    return 0;
}
