#define file "lca_rmq"
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <iostream>
#pragma comment(linker, "/STACK:100777216")

using namespace std;

const int MM(500100), N(200100);
int M, n, m, x[N], y[N], an[N];
int u[N / 2], no[MM], he[N / 2], ne[MM];
int d[N / 2], li[N], lin, F[N], t[N][30], lg[N];

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
        t[i][0] = li[i];
    for (int j = 1; j < 30; j++)
        for (int i = 0; i + (1 << j) <= lin; i++)
            t[i][j] = min_h(t[i][j - 1], t[i + (1<<(j - 1))][j - 1]);
}

int get(int l, int r) {
    int k = lg[r - l + 1];
    return min_h(t[l][k], t[r - (1<<k) + 1][k]);
}

int lca(int l, int r) {
    l = F[l]; r = F[r];
    if (l > r) {
        int t = l;
        l = r;
        r = t;
    }
    return get(l, r);
}

char s[20];
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    long long X, Y, Z, a, b, aa, bb, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(x, i);
    }
    for (int i = 0, j = 0; i <= 2 * n; i++) {
        for (; (1 << j) <= i; j++);
        lg[i] = j - 1;
    }
    dfs(0); build();
    for (int i = lin - 1; i >= 0; i--)
        F[li[i]] = i;
    cin >> a >> b;
    cin >> X >> Y >> Z;
    int last;
    last = lca(a, b); ans= last;
    for (int i = 2; i <= m; i++) {
        aa = X*a + Y*b + Z; aa = (aa + n) % n;
        bb = X*b + Y*aa + Z; bb = (bb + n) % n;
        a = aa; b = bb;//cerr << "a , b  " << a << " "<<b<<endl;
        last = lca((a+last)%n, b);
        ans += last;
    }
    cout << ans;
    return 0;
}

