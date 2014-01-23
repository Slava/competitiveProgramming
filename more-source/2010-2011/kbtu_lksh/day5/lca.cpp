#define file "lca"
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#pragma comment(linker, "/STACK:100777216")

using namespace std;

const int MM(500100), N(1000100);
int M, n, m, x[N], y[N], an[N];
int u[N / 2], no[MM], he[N / 2], ne[MM];
int d[N / 2], li[N], lin, F[N], t[N];

void add (int x, int y) {
    ++M; no[M] = y; ne[M] = he[x]; he[x] = M;
}

void dfs(int v) {
    u[v] = 1;
    li[lin++] = v;
    for (int i = he[v]; i; i = ne[i]) {
        int to = no[i];
        if (!u[to]) {
            d[to] = d[v] + 1;
            dfs(to);
            li[lin++] = v;
        }
    }
}

int min_h(int a, int b) {
    return d[a] > d[b] ? b : a;
}

void build() {
    for (int i = 0; i < lin; i++)
        t[i + lin] = li[i];
    for (int i = lin - 1; i >= 1; i--)
        t[i] = min_h(t[i + i], t[i + i + 1]);
}

int get(int l, int r) {
    d[0] = (1 << 30);
    int ans = 0; l += lin; r += lin;
    while(l <= r) {
        if (l & 1) ans = min_h(ans, t[l]);
        if (!(r&1)) ans = min_h(ans, t[r]);
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    return ans;
}

int lca(int l, int r) {
    l = F[l]; r = F[r];
    if (l > r) {
        int t = l;
        l = r;
        r = t;
    }
//    int k = lg[r - l + 1];
//    return min_h(st[l][k], st[r - (1 << k) + 1][k]);
    return get(l, r);
}

char s[20];
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d", s, x + i, y + i);
        if (s[0] == 'G')
            an[i] = 1;
        else {
            add(x[i], y[i]);
            add(y[i], x[i]);
        }
    }
    dfs(1);
    build();
    for (int i = lin - 1; i >= 0; i--)
        F[li[i]] = i;
    for (int i = 0; i < n; i++) {
        if (!an[i])continue;
        printf("%d\n", lca(x[i], y[i]));
    }
    return 0;
}

