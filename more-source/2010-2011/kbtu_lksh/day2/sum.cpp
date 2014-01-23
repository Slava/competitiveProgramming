#define file "sum"
#include <cstdio>

int t[200100], a[100100], n, k;
void inc(int i, int x) {
    for (; i < n; i |= i + 1)
        t[i] += x;
}

int sum(int i) {
    int r = 0;
    for (; i >= 0; i &= i + 1, i--)
        r += t[i];
    return r;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
    int l, r; char c;
    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%c %d %d\n", &c, &l, &r);
        if (c == 'A') {
            inc(l - 1, r - a[l - 1]);
            a[l - 1] = r;
        }
        else printf("%d\n", sum(l - 1, r - 1));
    }
    return 0;
}

