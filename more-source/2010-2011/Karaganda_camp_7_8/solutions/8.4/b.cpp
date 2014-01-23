// Sitmuhambetov Satjan
#include <cstdio>
int n, i, s, a[200009] = {1}, x, j;
int main ()
{
    scanf("%d%d", &s, &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (j = s; j >= 0; j--)
            if (a[j] == 1)
                a[j + x] = 1;
    }
    for (i = s; i >= 0; i--)
        if (a[i] == 1) {
            printf("%d", i);
            break;
        }
}