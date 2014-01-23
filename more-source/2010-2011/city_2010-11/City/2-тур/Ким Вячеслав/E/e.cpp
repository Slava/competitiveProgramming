#include <cstdio>
int a[1009][1009], i,j, m, n;
char s[1009];
int main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%s", s);
        for (j = 0; j < m; j++)
            a[i][j + 1] = s[j] - 48;
    }
    a[n][0] = 1;
    for (i = n; i >= 1; i--)
        for (j = 1; j <= m; j++)
            if (a[i][j] > 0)
                a[i][j] = a[i][j - 1] + a[i + 1][j];
    if (a[1][m] == 0) printf("impossible");
    else printf("%d",a[1][m]);
}
