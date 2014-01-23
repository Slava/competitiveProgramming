#include <cstdio>
#include <cstring>
#define min(a,b) (a<b?a:b)

int n, m, k, mm, ans, S, T;
int d[2100], from[2100];
struct edge {
    int x, y, c, f, cost;
    edge() {f = 0;}
}a[400000];

bool fordbellman() {
    memset(from, ~0, sizeof from);
    for (int i = 0; i < n; i++)
        d[i] = (1 << 30);
    d[S] = 0; from[S] = -2;
    bool found = 1;
    for (;found;) {
        found = 0;
        for (int i = 0; i < mm; i++) {
            if (a[i].c - a[i].f <= 0)continue;
            int x = a[i].x,
                y = a[i].y,
                c = a[i].cost;
            if (from[x] == -1)continue;
            if (d[y] > d[x] + c) {
                d[y] = d[x] + c;
                from[y] = i;
                found = 1;
            }
        }
    }
    return from[T] != -1;
}

int g[2100][2100];
main() {
    freopen("cubes.in", "r", stdin);
    freopen("cubes.out", "w", stdout);
    scanf("%d", &n);
    int sum = 0;
    S = n + n; T = S + 1;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x); sum += x;
        a[mm].x = S; a[mm].y = i; a[mm].cost = 0; a[mm].c = x; mm++;
        a[mm].x = i; a[mm].y = S; a[mm].cost = 0; a[mm].c = 0; mm++;
        a[mm].x = i; a[mm].y = i + n; a[mm].cost = 0; a[mm].c = x; mm++;
        a[mm].x = i + n; a[mm].y = i; a[mm].cost = 0; a[mm].c = 0; mm++;
    }
    for (int i = 0; i < n; i++) {
        int x = sum / n;
        a[mm].x = i + n; a[mm].y = T; a[mm].cost = 0; a[mm].c = x; mm++;
        a[mm].x = T; a[mm].y = i + n; a[mm].cost = 0; a[mm].c = 0; mm++;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            x = g[i][j];
            a[mm].x = i; a[mm].y = j + n; a[mm].cost = x; a[mm].c = (1 << 30); mm++;
            a[mm].y = i; a[mm].x = j + n; a[mm].cost = -x; a[mm].c = 0; mm++;
        }
    n = T + 1;
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
//        printf("%d\n", cost);
    }
//    puts("flow found");
    printf("%d\n", ans);
    return 0;
}

