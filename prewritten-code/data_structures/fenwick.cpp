// Kim Vyacheslav KarKTL
#include <cstdio>

int a[200], t[200], n;

void inc(int i, int delta) {
    for (; i < n; i = (i | (i + 1)))
        t[i] += delta;
}

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
        inc(i, a[i]);
    }
    int m, l, r;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        printf("sum(%d, %d) = %d\n", l, r, sum(l, r));
    }

    return 0;
}

