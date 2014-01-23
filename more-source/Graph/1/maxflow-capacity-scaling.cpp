// Kim Vyacheslav
// 2011
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;


#define forn(i,n) for(long i = 0; i < n; i++)
const long maxn = 600;
const long inf = 1 << 30;
long n, m, f[maxn][maxn], c[maxn][maxn], u[maxn];
queue<long>q;
bool bfs (long delta)
{
    long v;
    forn(i,n)u[i] = -1;
    u[0] = 0;
    q.push(0);
    while (q.size())
    {
        v = q.front();q.pop();
        forn(i,n)
            if (u[i] == -1 && c[v][i] - f[v][i] >= delta)
            {
                u[i] = v;
                q.push(i);
            }
    }
    return u[n - 1] != -1;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    long flow = 0;
    scanf ("%ld%ld", &n, &m);
    forn(i,m)
    {
        long a, b, w;
        scanf ("%ld%ld%ld", &a, &b, &w);
        c[--a][--b] = w;
    }
    for (long delta = inf; delta > 0; delta >>= 1)
        while (bfs(delta))
        {
            long M = inf;
            for(long t = n - 1; t; t = u[t])
                M = min(M, c[u[t]][t] - f[u[t]][t]);
            for(long t = n - 1; t; t = u[t])
                f[u[t]][t] += M,
                f[t][u[t]] -= M;
            flow += M;
        }
    printf("%ld", flow);
    return 0;
}

