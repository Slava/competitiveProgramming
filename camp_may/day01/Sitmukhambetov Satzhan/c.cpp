#include <cstdio>
long long i, j, cur ,pr, w, h, k1, k2, n, m, x, a, b, col, ans;
int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &w, &h, &k1, &k2, &n, &m); k2++;
	for (i = pr = 0; i <= n; i++) {
        if (i < n) scanf("%i64d", &cur);
        else cur = h;
        x = cur - pr;
        pr = cur;
        col = x - k1 * 2;
        if (col > 0) {
            a += col;
            col = x - k2 * 2;
            if (col > 0) {
                b += col;
            }
        }
	}
    for (i = pr = 0; i <= m; i++) {
        if (i < m) scanf("%i64d", &cur);
        else cur = w;
        x = cur - pr;
        pr = cur;
        col = x - k1 * 2;
        if (col > 0) {
            ans += a * col;
            col = x - k2 * 2;
            if (col > 0) {
                ans -= col * b;
            }
        }
    }
    printf("%I64d", ans);
}




