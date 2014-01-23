#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 50100 * 2;
typedef long long ull;
ull pr[N], p[N], P = 107LL, Q = 1717LL, prq[N], q[N];
int n, a[N], b[N], x;
inline ull hash(int l, int r) {
    ull h = pr[r];
    if (l)
        h -= pr[l - 1];
    h *= p[N - 1 - l];
    return h;
}

inline ull hahs(int l, int r) {
    ull h = prq[r];
    if (l)
        h -= prq[l - 1];
    h *= q[N - 1 - l];
    return h;
}
bool cmp(int f, int s) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (hash(f, f + m) == hash(s, s + m) &&
            hahs(f, f + m) == hahs(s, s + m))
            l = m + 1;
        else r = m - 1;
    }
    x = l;
    if (x == n)return 0;
    return a[f + l] < a[s + l];
}

int main() {
    freopen("towers.in", "r", stdin);
    freopen("towers.out", "w", stdout);

    p[N - 1] = q[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--)
        p[i] = p[i + 1] * P,
        q[i] = q[i + 1] * Q;
    for (;;) {
        if(scanf("%d", &n) != 1)return 0;
        for (int i = 0; i < n; i++)
            scanf("%d", a + i), a[i + n] = a[i], b[i] = i;
        for (int i = 0; i < n * 2; i++) {
            if (!i) pr[i] = prq[i] = 0;
            else pr[i] = pr[i - 1], prq[i] = prq[i - 1];
            pr[i] += p[i] * a[i];
            prq[i] += q[i] * a[i];
        }
        sort(b, b + n, cmp); long long ans = 0;
        for (int i = 1; i < n; i++) {
            cmp(b[i], b[i - 1]);
            ans += (long long)x;
        }
        cout << ans << endl;
    }
    return 0;
}

