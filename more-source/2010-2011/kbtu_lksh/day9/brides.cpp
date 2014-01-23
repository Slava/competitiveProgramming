#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>path[120];
int n, m, k, mm, ans;
int d[210], from[210];
struct edge {
    int x, y, c, f, cost;
    edge() {f = 0;}
}a[10000];

bool fordbellman() {
    memset(from, ~0, sizeof from);
    for (int i = 1; i < n; i++)
        d[i] = (1 << 30);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < mm; i++) {
            if (a[i].c - a[i].f <= 0)continue;
            int x = a[i].x,
                y = a[i].y,
                c = a[i].cost;
            if (d[y] > d[x] + c) {
                d[y] = d[x] + c;
                from[y] = i;
            }
        }
    return from[n - 1] != -1;
}

void dfs(int v, int k) {
//    printf(">> %d, %d\n", v, k);
    if (v == n - 1)
        return;
    for (int i = 0; i < mm; i++)
        if (a[i].x == v && a[i].f == 1 && a[i].c == 1) {
            ans += a[i].cost;
            path[k].push_back(i / 4 + 1);
            a[i].f = 0;
            dfs(a[i].y, k);
            break;
        }
}

int main() {
    freopen("brides.in", "r", stdin);
    freopen("brides.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--; y--;
        a[mm].x = x; a[mm].y = y; a[mm].cost = z; a[mm].c = 1; mm++;
        a[mm].x = y; a[mm].y = x; a[mm].cost = -z; a[mm].c = 0; mm++;
        a[mm].x = x; a[mm].y = y; a[mm].cost = -z; a[mm].c = 0; mm++;
        a[mm].x = y; a[mm].y = x; a[mm].cost = z; a[mm].c = 1; mm++;
    }
    for (int j = 0; j < k; j++) {
        if (!fordbellman()) {
            printf("-1\n");
            return 0;
        }
        int v = n - 1, e = from[v], cost = 0;
        while (e != -1) {
            a[e].f++;
            a[e^1].f--;
            cost += a[e].c;
            v = a[e].x;
            e = from[v];
        }
    }
//    puts("flow found");
    for (int i = 0; i < k; i++)
        dfs(0, i);
    printf("%.5lf\n", (double)ans / k);
    for (int i = 0; i < k; i++) {
        printf("%d ", path[i].size());
        for (int j = 0; j < path[i].size(); j++)
            printf("%d ", path[i][j]);
        printf("\n");
    }
    return 0;
}

