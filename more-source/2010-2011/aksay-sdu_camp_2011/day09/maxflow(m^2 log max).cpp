#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1000;

int c[maxn][maxn], f[maxn][maxn], s, t, flow,
    Mn, T, n, u[maxn], path[maxn], i, j, inf = (1 << 30);

bool Bfs (int s, int t, int maxc)
{
    for (i = 1; i <= n; i++)
        u[i] = false;
    queue <int> q;
    q.push(s);
    while (q.size())
    {
        int v = q.front();q.pop();
        for (i = 1; i <= n; i++)
            if (!u[i] && c[v][i] - f[v][i] >= maxc)
            {
                u[i] = 1;
                q.push(i);
                path[i] = v;
            }
    }
    return u[t];
}

int main ()
{
    scanf ("%d%d%d", &n, &s, &t);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf ("%d", &c[i][j]);

    int maxc = inf;
    while (maxc > 0)
    {
        while (Bfs(s, t, maxc))
        {
            T = t;
            Mn = inf;
            while (T != s)
            {
                Mn = min(Mn, c[path[T]][T] - f[path[T]][T]);
                T = path[T];
            }
            T = t;
            while (T != s)
            {
                f[path[T]][T] += Mn;
                f[T][path[T]] -= Mn;
                T = path[T];
            }
            flow += Mn;
        }
    maxc /= 2;
    }

    printf ("%d", flow);

    return 0;
}

