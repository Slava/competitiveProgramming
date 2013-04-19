#include <cstdio>
#include <cstring>

inline void swap (long &a, long &b)
{
	long t = a;
	a = b;
	b = t;
}

const int N = 10106;
long n, logn, res, A, B, k, t;
long h[N], u[N], g[N][N], d[N][30], dist[N];
char s[10];

void dfs(long v, long p = -1)
{
    u[v] = true;
    if (p != -1)
		h[v] = h[p] + 1;
	d[v][0] = p;
    if(p != -1)
		dist[v] = dist[p] + g[p][v];
    for (long i = 1; i <= logn; i++)
        d[v][i] = d[d[p][i - 1]][i - 1];
    for (long i = 0; i < n; i++)
        if (g[v][i] && !u[i])
            dfs(i, v);

}

long lca (long u, long v)
{
    res = dist[u] + dist[v];
    if (h[u] < h[v])
        swap (u, v);
    for (long i = logn; i >= 0; i--)
        if (d[u][i] != -1 &&
                h[d[u][i]] >= h[v])
                u = d[u][i];
    if (u == v)
    {
        res -= 2 * dist[u];
        return u;
    }
    for (long i = logn; i >= 0; i--)
        if (d[u][i] != -1 &&
                d[u][i] != d[v][i])
                   u = d[u][i], v = d[v][i];
    res -= 2 * dist[d[v][0]];
    return d[v][0];
}

long kth (long u, long v, long k)
{
    long uvlca = lca(u, v), need;
    long midl = h[u] + h[v] - 2 * h[uvlca] + 1;
    if (k == 1)
        return u;
    if (k == midl)
        return v;
    if (k == h[u] - h[uvlca] + 1)
        return uvlca;

    if (k < h[u] - h[uvlca] + 1)
    {
        need = k - 1;
        for(long log = logn; log >= 0; log--)
            if ((1 << log) <= need)
            {
                need -= 1 << log;
                u = d[u][log];
            }
        return u;
    }
    need = midl - k;
    for(long log = logn; log >= 0; log--)
        if ((1 << log) <= need)
        {
            need -= 1 << log;
            v = d[v][log];
        }
    return v;
}

void solve ()
{
    scanf ("%ld", &n);

    for (logn = 1; (1 << logn) <= n; logn++);
    logn--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= logn; j++)
			d[i][j] = -1;

    for (long i = 1, f, t; i < n; i++)
    {
        scanf ("%ld%ld", &f, &t);
        --f;
        --t;
        scanf ("%ld", &g[f][t]);
        g[t][f] = g[f][t];
    }

    dfs(0);
    while (true)
    {
        scanf ("%s", s);
        k = 0;
        if (!strcmp("DONE", s))
            break;
        if (!strcmp("KTH", s))
        {
            scanf ("%ld %ld %ld ", &A, &B, &k);
            printf("%ld\n", kth(A - 1, B - 1, k) + 1);
        }
        else
        {
            scanf ("%ld%ld", &A, &B);
            lca(A - 1,B - 1);
            printf ("%ld\n", res);
        }
    }
    puts("");
    for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = 0;
	for (int i = 0; i < n; i++)
		dist[i] = u[i] = h[i] = 0;
}

int main ()
{
    scanf("%ld", &t);
    while(t--){
        solve();
    }

    return 0;
}

