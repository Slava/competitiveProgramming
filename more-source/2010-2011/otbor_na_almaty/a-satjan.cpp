#include <cstdio>
#include <cmath>
double x;
int i, n, m, j, k , l, a[99], b[99], aa[99], bb[99], p, c[99], r;
int main () {
    freopen("bacteria.in","r",stdin);
    freopen("bacteria.out","w",stdout);

    scanf("%d%d", &n, &m);
    x = (double)n;
    for (j = 2; j <= sqrt(x); j++) {
        x = (double)n;
        if  (n % j == 0) {
            a[l] = j;
            for (i = 0; n % j == 0; i++)
                n /= j;
            aa[l] = i;
            l++;
        }
    }
    if (n > 1) {
        a[l] = n;
        aa[l] = 1;
        l++;
    }
    k = l; l = 0;
    x = (double)m;
    for (j = 2; j <= sqrt(x); j++) {
        x = (double)m;
        if  (m % j == 0) {
            b[l] = j;
            for (i = 0; m % j == 0; i++)
                m /= j;
            bb[l] = i;
            l++;
        }
    }
    if (m > 1) {
        b[l] = m;
        bb[l] = 1;
        l++;
    }
    for (i = 0; i < l; i++) {
        p = 0;
        for (j = 0; j < k; j++)
            if (b[i] == a[j])
                p = 1;
        if (p == 0) break;
    }
    if (i < l) printf("Impossible");
    else {
        for (i = 0; i < k; i++) {
            p = 0;
            for (j = 0; j < l; j++)
                if (a[i] == b[j])
                    p = 1;
            if (p == 0) c[i] = 1;
        }
        for (i = 0; i < k; i++) {
            if (c[i] == 1) {
                while (aa[i] > 0) {
                    printf("%d ", a[i]);
                    aa[i]--;
                }
                a[i] = 0;
            }
        }
        for (i = j = 0; i < k; i++) {
            if (a[i] > 0) {
                a[j] = a[i];
                aa[j] = aa[i];
                j++;
            }
        }
        n = k = j;
        for (;;) {
            m = 0;
            for (i = 0; i < n; i++) {
                k = aa[i];
                l = bb[i];
                for (r = 0; k < l; r++)
                    k *= 2;
                if (r > m) m = r;
            }
            for (r = 1; m > 0; r *= 2) m--;
            p = 0;
            for (i = 0; i < n; i++) {
                for (j = 0;aa[i] * r >= bb[i]; j++)
                    aa[i]--;
                for ( ; j > 1; j--)
                    printf("%d ", a[i]);
                aa[i]++;
                if (aa[i] != bb[i]) p = 1;
            }
            if (p == 0) break;
            else {
                for (i = 0; i < n; i++)
                    aa[i] *= 2;
                printf("0 ");
            }
            k = l = n;
        }
    }
}
