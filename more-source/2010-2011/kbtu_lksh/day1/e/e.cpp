#define file "connect"
#include <cstdio>
#include <queue>
#include <iostream>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

int n, m, x[200100], y[200100], st[20100], u[20100], c;
vector<int>g[100010];

void dfs(int v) {
    u[v] = c;
    for (int i = 0; i < g[v].size(); i++)
        if (!u[g[v][i]])
            dfs(g[v][i]);
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", x + i, y + i);
        st[x[i]]++; st[y[i]]++;
    }
    for (int i = 1; i <= n; i++)
        g[i].reserve(st[i]);
    for (int i = 0; i < m; i++) {
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }

    for (int i = 1; i <= n; i++)
        if (!u[i]) {
            c++; dfs(i);
        }
    printf("%d\n", c);
    for (int i = 1; i <= n; i++)
        printf("%d ", u[i]);

    return 0;
}
