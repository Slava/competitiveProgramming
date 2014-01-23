#define file "cutting"
#include <cstdio>
#include <cstdlib>

const int N = 150100;
int p[N], n, m, k, x[N], y[N], cmd[N], ans[N];
char s[20];

int find(int x) {
    if (p[x] != x)
        return p[x] = find(p[x]);
    return p[x];
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (rand() & 1)
        p[x] = y;
    else p[y] = x;
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
        scanf("%d%d", x, y);
    for (int i = 0; i < k; i++) {
        scanf("%s%d%d", s, x + i, y + i);
        cmd[i] = s[0] == 'a';
    }
    for (int i = k - 1; i >= 0; i--) {
        if (cmd[i])
            ans[i] = find(x[i]) == find(y[i]);
        else unite(x[i], y[i]);
    }
    for (int i = 0; i < k; i++)
        if (cmd[i])
            printf("%s\n", ans[i] ? "YES" : "NO");
    return 0;
}

