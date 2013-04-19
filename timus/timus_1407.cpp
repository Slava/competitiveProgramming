#include <cstdio>
int n, i, j, a[409], k, b[409], l, c;
int main () {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        a[i] = 1;
        for (j = 1; j <= i; j++)
            b[j] = a[j];
        l = i;
        for (j = c = 0; j < i; j++) {
            for (k = l;k > 0; k--) {
                c = b[k] + c * 10;
                b[k] = c / 2;
                c = c % 2;
                if (b[k] == 0 && k == l) l--;
            }
            if (c > 0) break;
        }
        if (c > 0) a[i] = 2;
    }
    for (i = n; i > 0; i--)
        printf("%d", a[i]);
}
