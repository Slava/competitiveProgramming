#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[500100], x[300100], y[300100], p[500100];
int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", x + i, y + i);
        a[i * 2] = x[i];
        a[i * 2 + 1] = y[i];
    }
    sort(a, a + n + n);
    int m = unique(a, a + n + n) - a;
    for (int i = 0; i < m; i++)
        p[i] = a[i];
    for (int i = 0; i < n; i++) {
        int l, r;
        l = lower_bound(a, a + m, x[i]) - a;
        r = lower_bound(a, a + m, y[i]) - a;
        printf("%d\n", abs(p[r] - p[l]));
        swap(p[l], p[r]);
    }
    return 0;
}
