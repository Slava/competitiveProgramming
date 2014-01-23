#define file "kth"
#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:100777216")

const int N = 100200;
int A[N * 20], L[N * 2], R[N * 2], M, a[N], n, m;
int inf = (int)1e9 + 100;

void merge(int i, int n, int j, int m, int k) {
    while (i <= n && j <= m)
        if (A[i] < A[j])
            A[k++] = A[i++];
        else A[k++] = A[j++];
    while (i <= n) A[k++] = A[i++];
    while (j <= m) A[k++] = A[j++];
}

void build() {
    for (int i = 0; i < n; i++) {
        L[i + n] = R[i + n] = M; A[M] = a[i]; M++;
    }
    for (int i = n - 1; i >= 1; i--) {
        int sz = R[i + i] - L[i + i] + R[i + i + 1] - L[i + i + 1] + 2;
        L[i] = M; R[i] = M + sz - 1; M += sz;
        merge(L[i + i], R[i + i], L[i + i + 1], R[i + i + 1], L[i]);
    }
}

int count(int l, int r, int x) {
    int m, ll = l;
    while (l <= r) {
        m = (l + r) / 2;
        if (A[m] < x)
            l = m + 1;
        else r = m - 1;
    }
    return l - ll;
}

int get(int l, int r, int x) {
    l += n; r += n; int ans = 0;
    while(l <= r) {
        if (l & 1) ans += count(L[l], R[l], x);
        if (!(r & 1)) ans += count(L[r], R[r], x);
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    return ans;
}

int query(int i, int j, int k) {
    i--; j--; k--;
    int l = -inf, r = inf, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (get(i, j, m) <= k)
            l = m + 1;
        else r = m - 1;
    }
    return l - 1;
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    build();
    for (int i = 0; i < m; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", query(l, r, k));
    }

    return 0;
}
