// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>


int main ()
{
    int n, i, j;
    scanf ("%d", &n);
    printf ("%d\n", n / 2 * (n - n / 2));
    for (i = 1; i <= n / 2; i++)
        for (j = n / 2 + 1; j <= n; j++)
            printf ("%d %d\n", i, j);

    return 0;
}

