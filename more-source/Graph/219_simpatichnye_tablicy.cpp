#include <cstdio>

using namespace std;

#define min(x,y) (x<y?x:y)

const int maxn = 700;
int n, m, i, j, ans, a[maxn][maxn],
    q[99999], u[maxn], h, t, path[maxn],
    f[maxn][maxn], 
    z[maxn][maxn], inf = 1 << 30,
    C[maxn], R[maxn];

bool bfs (int S = n + m, int T = n + m + 1)
{
    h = t = 0;
    q[t++] = S;
    for (i = 0; i <= T; i++)
        u[i] = false;
    u[S] = true;
    while (h < t)
    {
        int v = q[h++];
        for (j = 0; j <= T; j++)
            if (f[v][j] > 0 && !u[j])
            {
                u[j] = true;
                path[j] = v;
                q[t++] = j;
            }
    }
    return u[T];
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    
    scanf ("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf ("%d", &R[i]);
    for (i = 0; i < m; i++)
        scanf ("%d", &C[i]);
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            scanf ("%d", &z[i][j]);
            if (z[i][j] == -1)
            {
                f[i][j + n] = inf;
                z[i][j] = 0;
            }
            ans += z[i][j];
            R[i] -= z[i][j];
            C[j] -= z[i][j];
            f[n + m][i] = R[i];
            f[n + j][n + m + 1] = C[j];
            if (C[j] < 0 || R[i] < 0)
            {
                puts("-1");
                return 0;
            }
        }

    while (bfs())
    {
        int v = n + m + 1,
            M = inf;
        while (v != n + m)
        {
            M = min(M, f[path[v]][v]);
            v = path[v];
        }
        v = n + m + 1;
        while (v != n + m)
        {
            f[path[v]][v] -= M;
            f[v][path[v]] += M;
            v = path[v];
        }
        ans += M;
    }
    
    
    printf ("%d", ans);

    return 0;
}

