#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define dbg(x) cout<<#x<<" = "<<x<<"\n";
#define pb push_back

const int N = 10006;
int n, logn, res, A, B, k, t;
int h[N], d[N][20], dist[N][20];
bool u[N];
vector<int>g[N], w[N];

void dfs(int v, int p = 0)
{
    u[v] = true;
    h[v] = h[p] + 1;
    d[v][0] = p;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] == p){
            dist[v][0] = w[v][i];
            break;
        }
    for (int i = 1; i <= logn; i++)
        d[v][i] = d[d[p][i - 1]][i - 1],
        dist[v][i] = dist[p][i - 1] + dist[d[p][i - 1]][i - 1];
    for (int i = 0; i < g[v].size(); i++)
        if (!u[g[v][i]])
            dfs(g[v][i], v);

}

int lca (int u, int v)
{
    res = 0;
    if (h[u] < h[v])
        swap (u, v);
    for (int i = logn; i >= 0; i--)
        if (d[u][i] != -1 &&
            h[d[u][i]] >= h[v])
            res += dist[u][i],u = d[u][i];
    if (u == v)
        return u;
    for (int i = logn; i >= 0; i--)
        if (d[u][i] != -1 &&
            d[u][i] != d[v][i])
            res += dist[u][i] + dist[v][i],
            u = d[u][i], v = d[v][i];
    res += dist[v][0] + dist[u][0];
    return d[v][0];
}

int kth (int u, int v, int k)
{
    int uvlca = lca(u, v), need;
    int midl = h[u] + h[v] - 2 * h[uvlca] + 1;
    if (k == 1)
        return u;
    if (k == midl)
        return v;
    if (k == h[u] - h[uvlca] + 1)
        return uvlca;

    if (k < h[u] - h[uvlca] + 1)
    {
        need = k - 1;
        for(int log = logn;log >= 0;log--)
            if ((1 << log) <= need)
            {
                need -= 1 << log;
                u = d[u][log];
            }
        return u;
    }
    need = midl - k;
    for(int log = logn;log >= 0;log--)
        if ((1 << log) <= need)
        {
            need -= 1 << log;
            v = d[v][log];
        }
    return v;
}

void solve ()
{
    scanf ("%d", &n);

    for (logn = 1; (1 << logn) <= n; logn++);


    for (int i = 1, f, t, W; i < n; i++)
    {
        scanf ("%d%d%d", &f, &t, &W);
        g[f].pb(t);w[f].pb(W);
        g[t].pb(f);w[t].pb(W);
    }

    dfs(0);
    char s[100];
    while (true)
    {
        scanf ("%s", s);
        k = 0;
        if (s[1] == 'O')
            break;
        if (s[1] == 'T'){
            scanf ("%d%d%d", &A, &B, &k);
            printf("%d\n", kth(A - 1, B - 1, k) + 1);
        }
        if (s[1] == 'I'){
            scanf ("%d%d", &A, &B);
            lca(A - 1,B - 1);
            printf ("%d\n", res);
        }
    }
    for (int i = 0; i < n; i++)
        g[i].clear(), w[i].clear();
    memset (u, 0, sizeof(u));
    memset (d, -1, sizeof(d));
    memset (dist, 0, sizeof(dist));
    memset (h, 0, sizeof(h));
}

int main ()
{
    scanf("%d", &t);
    while(t--)
        solve();

    return 0;
}

