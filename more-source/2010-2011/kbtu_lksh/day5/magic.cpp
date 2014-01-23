#define file "magic"
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:100777216")

using namespace std;

const int MM(1000100), N(200100);
int M, n, m, f, no[MM], he[N], ne[MM], ign[MM];
int u[N], c[N], col, tin[N], fup[N], timer, d[N];
set<int>D[N];

// compressed
vector<int>g[N];
int li[N * 2], lin, F[N], t[N * 4];

void dfs_comp(int v) {
    u[v] = 1;
    li[lin++] = v;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!u[to]) {
            d[to] = d[v] + 1;
            dfs_comp(to);
            li[lin++] = v;
        }
    }
}

void build() {
    for (int i = 0; i < lin; i++)
        t[i + lin] = d[li[i]];
    for (int i = lin - 1; i >= 1; i--)
        t[i] = min(t[i + i], t[i + i + 1]);
}

int get(int l, int r) {
    int ans = (1 << 30); l += lin; r += lin;
    while(l <= r) {
        if (l & 1) ans = min(ans, t[l]);
        if (!(r&1)) ans = min(ans, t[r]);
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

void bridge(int x, int y) {
//    fprintf(stderr, "bridge %d %d\n", x, y);
    D[x].insert(y);
    D[y].insert(x);
}

void add (int x, int y) {
    ++M; no[M] = y; ne[M] = he[x]; he[x] = M;
}

void dfs(int v, int p = -1) {
    u[v] = 1;
    tin[v] = fup[v] = timer++;
    for (int i = he[v]; i; i = ne[i]) {
        int to = no[i];
        if (to == p)
            continue;
        if (u[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (tin[v] < fup[to])
                bridge(to, v);
        }
    }
}

void color(int v) {
//    fprintf(stderr, "%d ", v);
    u[v] = 1; c[v] = col;
    for (int i = he[v]; i; i = ne[i])
        if (!ign[i] && !u[no[i]])
            color(no[i]);
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &f);
    if(n >= N || m >= MM)return 1;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }

    dfs(f);
    for (int i = 1; i <= n; i++)
        for (int j = he[i]; j; j = ne[j])
            if (D[i].find(no[j]) != D[i].end())
                ign[j] = 1;

    memset(u, 0, sizeof u);
    for (int i = 1; i <= n; i++)
        if (!u[i]) {
            col++;
//            fprintf(stderr, "colored %d: ", col);
            color(i);
//            fprintf(stderr, "\n");
        }
    for (int i = 1; i <= n; i++)
        for (int j = he[i]; j; j = ne[j])
            if (ign[j])
                g[c[i]].push_back(c[no[j]]);
    memset(u, 0, sizeof u); dfs_comp(c[f]);
    //build_st();
    build();
    for (int i = lin - 1; i >= 0; i--)
        F[li[i]] = i;
    scanf("%d", &m);
    for (int x, y;m--;) {
        scanf("%d%d", &x, &y);
        x = c[x]; y = c[y];
        x = lca(x, y);
        printf("%d\n", x);
    }
    return 0;
}

