#define file "bfsrev"
#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

const int N = 1000000;
int n, m, d[100010], s;
int x, y, no[N], ne[N], he[100010];
int q[1000100], h, t, M;
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d%d%d", &n, &s, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y); M++;
        no[M] = x; ne[M] = he[y]; he[y] = M;
    }
    for (int i = 1; i <= n; i++)
        d[i] = (1 << 30);
    d[s] = 0;
    q[t++] = s;
    while (h < t) {
        int v = q[h++];
        for (int i = he[v]; i; i = ne[i]) {
            int to = no[i];
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q[t++] = to;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", d[i] < (1<<30) ? d[i] : -1);
    return 0;
}
