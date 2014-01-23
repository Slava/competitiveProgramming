// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

long n, ans = 0, a[60][60];

void f (int i, int j)
{
    if (a[i][j]) return;
    if (a[i+1][j] == 1) ans++;
    if (a[i][j+1] == 1) ans++;
    if (a[i-1][j] == 1) ans++;
    if (a[i][j-1] == 1) ans++;
    a[i][j] = 2;
    f (i + 1, j);
    f (i - 1, j);
    f (i, j + 1);
    f (i, j - 1);
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char s[60];

    scanf ("%ld", &n);
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++)
            a[i][j] = 1;

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < n; j++)
            a[i][j+1] = (s[j] == '#');
    }

    f(1,1);
    f(n,n);

    printf ("%ld", ans * 25 - 100);

    return 0;
}

