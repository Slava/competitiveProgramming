// dinica
// maxflow
#include <cstdio>
#include <cstring>
#define min(a,b) (a<b?a:b)

const long maxn = 1000;
long l[maxn], f[maxn][maxn], c[maxn][maxn],
    s, t, n, m, q[maxn], j[maxn];

bool bfs ()
{
    memset(l, -1, sizeof(l[0]) * n);
    long qh, qt;
    qh = qt = 0;
    q[qt++] = s;
    l[s] = 0;

    while (qh < qt)
    {
        long v = q[qh++];
        for (long i = 0; i < n; i++)
            if (l[i] == -1 && c[v][i] - f[v][i] > 0)
            {
                l[i] = l[v] + 1;
                q[qt++] = i;
            }
    }

    return l[t] != -1;
}

long dfs (long v, long flow)
{
    if (!flow)
        return 0;
    if (v == t)
        return flow;
    for (; j[v] < n; j[v]++)
        if (l[j[v]] == l[v] + 1)
        {
            long pushed = dfs (j[v], min(flow, c[v][j[v]] - f[v][j[v]]));
            if (pushed)
            {
                f[v][j[v]] += pushed;
                f[j[v]][v] -= pushed;
                return pushed;
            }
        }
    return 0;
}

long dinic ()
{
    long flow = 0, pushed;
    while (bfs())
    {
        memset (j, 0, sizeof(j[0]) * n);
        while (pushed = dfs(s, 1 << 30))
            flow += pushed;
    }
    return flow;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld%ld", &n, &m);
    for (long a, b, w; m--;)
    {
        scanf ("%ld%ld%ld", &a, &b, &w);
        c[--a][--b] = w;
    }
    t = n - 1;
    printf("%ld", dinic());

    return 0;
}

