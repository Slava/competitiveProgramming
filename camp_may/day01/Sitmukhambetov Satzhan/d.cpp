#include <cstdio>
const int M = 1009;
const int N = 1000000;
int n, k, A, B, S, x[N + 9], y[N + 9], l[M], r[M],
    i, j, d[M][M], be, en, tm, ok, p[M][M];

long long ans[M][M], cur, cnt, a[M], t;

bool u[M][M];
int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d%d", &n, &k, &A, &B, &S);
	for (i = 1; i <= n + 1; i++) {
        if (i <= n)
            scanf("%I64d", &a[i]);
        else a[i] = S;
	}
	for (i = 0; i <= n; i++) {
	    ok = 0;
        for (j = i + 1; j <= n + 1; j++) {
            t = a[j] - a[i];
            if (t < A) continue;
            if (ok == 0) l[i] = j, ok = 1;
            if (t <= B) {
                d[i][j] = t;
            }
            else {
                r[i] = j - 1;
                ok = 2;
                break;
            }
        }
        if (ok == 0) l[i] = n + 2;
        if (ok == 1) r[i] = n + 1;
	}

	u[0][0] = 1;
    x[0] = 0; y[0] = 0;
    for (be = 0, en = 1; be != en; ) {
        i = x[be];
        tm = y[be];
        for (j = l[i]; j <= r[i]; j++) {
            if (n - j < k - tm - 1 || k - tm - 1 < 0) break;
            ok = 0;
            if (tm > 0)
                cnt = 2 * 1ll * ans[i][tm] - ans[p[i][tm]][tm - 1] + d[i][j] * 1ll * tm;
            cur = ans[j][tm + 1];

            if (u[j][tm + 1] == 0)
                u[j][tm + 1] = ok = 1;
            else
                if (cnt > cur)
                    ok = 1;
            if (ok) {
                ans[j][tm + 1] = cnt;
                p[j][tm + 1] = i;
                x[en] = j;
                y[en] = tm + 1;
                en++;
                if (en > 1000000) en = 0;
            }
        }
        be++;
        if (be > N) be = 0;
    }
    cnt = 0;
    for (i = 0; i <= n; i++)
        if (d[i][n + 1] != 0)
            if (u[i][k])
                if (cnt < ans[i][k])
                    cnt = ans[i][k];

    printf("%I64d", cnt * 1ll * 2);
}


