#include <cstdio>
#include <cstring>
#define min(a,b) (a<b?a:b)
#define abs(x) (x<0?-(x):x)

int n, m, k, mm, ans, S, T;
int d[500], from[500];
struct edge {
    int x, y, c, f, cost;
    edge() {f = 0;}
}a[400000];

bool fordbellman() {
    memset(from, ~0, sizeof from);
    for (int i = 0; i < n; i++)
        d[i] = (1 << 30);
    d[S] = 0;
    bool found = 1;
    for (;found;) {
        found = 0;
        for (int i = 0; i < mm; i++) {
            if (a[i].c - a[i].f <= 0)continue;
            int x = a[i].x,
                y = a[i].y,
                c = a[i].cost;
            if (d[y] > d[x] + c) {
                d[y] = d[x] + c;
                from[y] = i;
                found = 1;
            }
        }
    }
    return from[T] != -1;
}

int x[500], y[500], their, st, oldn;
int A[500][500];
int dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]) + 1;
}

int main() {
    freopen("evacuate.in", "r", stdin);
    freopen("evacuate.out", "w", stdout);
    scanf("%d%d", &n, &m); oldn = n;
    S = n + m; T = S + 1;
    for (int i = 0; i < n; i++) {
        int _;
        scanf("%d %d %d ", x + i, y + i, &_);
        a[mm].x = S; a[mm].y = i; a[mm].c = _; a[mm].cost = 0; mm++;
        a[mm].x = i; a[mm].y = S; a[mm].c = 0; a[mm].cost = 0; mm++;
    }
    for (int i = n; i < n + m; i++) {
        int _;
        scanf("%d %d %d ", x + i, y + i, &_);
        a[mm].x = i; a[mm].y = T; a[mm].c = _; a[mm].cost = 0; mm++;
        a[mm].x = T; a[mm].y = i; a[mm].c = 0; a[mm].cost = 0; mm++;
    }
    st = mm;
    for (int i = 0; i < n; i++)
        for (int j = n; j < n + m; j++) {
            a[mm].x = i; a[mm].y = j; a[mm].c = 10000000; a[mm].cost = dist(i, j); mm++;
            a[mm].x = j; a[mm].y = i; a[mm].c = 0; a[mm].cost = -dist(i, j); mm++;
            a[mm].x = j; a[mm].y = i; a[mm].c = 10000000; a[mm].cost = dist(i, j); mm++;
            a[mm].x = i; a[mm].y = j; a[mm].c = 0; a[mm].cost = -dist(i, j); mm++;
        }

    for (int i = 0; i < n; i++)
        for (int j = n; j < n + m; j++) {
            int _;
            scanf("%d", &_);
            their += _ * dist(i, j);
        }
    n = T + 1;
    for (;fordbellman();) {
        int v = T, e = from[v], cost = 0, M = (1 << 30);
        while (e != -1) {
            M = min(M, a[e].c - a[e].f);
            v = a[e].x;
            e = from[v];
        }
        v = T; e = from[v];
        while (e != -1) {
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
    if (their == ans) {
        printf("OPTIMAL");
        return 0;
    }
    printf("SUBOPTIMAL\n");
    for (int i = st; i < mm; i += 2)
        if (a[i].f > 0 && a[i].c > 0)
            A[a[i].x][a[i].y] += a[i].f;
    for (int i = 0; i < oldn; i++)
        for (int j = oldn; j < oldn + m; j++)
            printf("%d%c", A[i][j], " \n"[j == oldn + m - 1]);
    return 0;
}

