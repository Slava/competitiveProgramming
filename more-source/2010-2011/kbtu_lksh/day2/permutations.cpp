#define file "permutations"
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 100100;

struct query {
    int x, l, r, i, o;
}qu[N * 2], q;
bool operator < (query a, query b) {
    return a.x < b.x;
}
int ans[N][2], n, m, t[N + 100], a[N], wh[N];
void inc(int i, int x) {
    for (; i <= n; i |= i + 1)
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

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        wh[a[i]] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y, k, l;
        scanf("%d%d%d%d", &x, &y, &k, &l);
        q.o = 0; q.i = i; q.l = x; q.r = y; q.x = k - 1;
        qu[i * 2] = q; q.o = 1; q.x = l; qu[i * 2 + 1] = q;
    }
    sort(qu, qu + m + m); int j = 0;
    for (int k = 0; k <= n; k++) {
        //fprintf(stderr, "%d\n", k);
        inc(wh[k], 1);
        for (; j < m + m && qu[j].x == k; j++)
            ans[qu[j].i][qu[j].o] = sum(qu[j].l, qu[j].r);
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i][1] - ans[i][0]);

    return 0;
}

