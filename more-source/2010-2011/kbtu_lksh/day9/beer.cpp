#include <cstdio>
#include <cstring>
#define min(a,b) (a<b?a:b)
#define abs(x) (x<0?-(x):x)

int n, m, k, mm, ans, S, T, gans;
int d[500], from[500];
struct edge {
    int x, y, c, f, cost;
    edge() {f = 0;}
}a[400000];

bool fordbellman() {
    for (int i = 0; i < n; i++)
        d[i] = (1 << 30), from[i] = -1;
    d[S] = 0; from[S] = -2;
    bool found = 1;
    for (;found;) {
        found = 0;
        for (int i = 0; i < mm; i++) {
            if (a[i].c - a[i].f <= 0)continue;
            int x = a[i].x,
                y = a[i].y,
                c = a[i].cost;
            if (from[x] != -1)
            if (d[y] > d[x] + c) {
                d[y] = d[x] + c;
                from[y] = i;
                found = 1;
            }
        }
    }
    return from[T] != -1;
}

int go(int V) {
    for (int i = 0; i < mm; i++) {
        a[i].f = 0;
        if (a[i].x == S && a[i].y == 0)
            a[i].c = V;
    }
    ans = 0;
    for (;fordbellman();) {
        int v = T, e = from[v], cost = 0, M = (1 << 30);
        while (e != -2) {
            M = min(M, a[e].c - a[e].f);
            v = a[e].x;
            e = from[v];
        }
        v = T; e = from[v];
        while (e != -2) {
            a[e].f += M;
            a[e^1].f -= M;
            cost += a[e].cost * M;
            v = a[e].x;
            e = from[v];
        }
        ans += cost;
        gans = min(gans, ans);
    }
    return ans;
}

int main() {
    freopen("beer.in", "r", stdin);
    freopen("beer.out", "w", stdout);
    scanf("%d%d", &n, &m);
    T = n;
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        x = -x;
        a[mm].x = i; a[mm].y = T; a[mm].c = 1000000000; a[mm].cost = x; mm++;
        a[mm].x = T; a[mm].y = i; a[mm].c = 0; a[mm].cost = -x; mm++;
    }
    for (int i = 0; i < m; i++) {
        int x, y, c, cost;
        scanf("%d%d%d%d", &x, &y, &c, &cost); x--; y--;
        a[mm].x = x; a[mm].y = y; a[mm].c = c; a[mm].cost = cost; mm++;
        a[mm].x = y; a[mm].y = x; a[mm].c = 0; a[mm].cost = -cost; mm++;
        a[mm].x = y; a[mm].y = x; a[mm].c = c; a[mm].cost = cost; mm++;
        a[mm].x = x; a[mm].y = y; a[mm].c = 0; a[mm].cost = -cost; mm++;
    }
    n++; S = n; n++;
    a[mm].x = S; a[mm].y = 0; a[mm].c = 0; a[mm].cost = 0; mm++;
    a[mm].x = 0; a[mm].y = S; a[mm].c = 0; a[mm].cost = 0; mm++;

    go(1<<30);
    printf("%d\n", -gans);
    return 0;
}

