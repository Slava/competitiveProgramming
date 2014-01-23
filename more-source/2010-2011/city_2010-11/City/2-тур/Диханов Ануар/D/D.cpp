#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXN 100001

using namespace std;

int l[MAXN], u[MAXN], ld[MAXN], lf[MAXN], uh[MAXN], c[MAXN], lc,  lb, p, h,
    o = 1, mx, m, n;
pair < int, pair <int, int > > ans[MAXN];
vector < int >  a[MAXN], d[MAXN], f[MAXN];

int p3(int, int);
void r2(int, int, int, int, int);
void r1(int, int);

main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    int i, x, y;
    scanf ("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf ("%d%d", &x, &y);
        a[x].push_back(y);
        l[x]++;
        a[y].push_back(x);
        l[y]++;
    }
    r1(1, 0);
    for (i = 1; i <= n; i++) u[i] = 0;
    r2(o, 0, 0, 1, 0);
    sort(ans, ans + lb);
    for (i = 0; i < lb; i++)
        printf("%d %d\n", ans[i].second.first, ans[i].second.second);
}

int p3(int k, int p)
{
    int i, j;
    bool T = 0;
    for (i = 0; i < ld[k]; i++)
        for (j = 0; j < ld[p]; j++)
            if (d[k][i] == d[p][j])
                return T;
    T = 1;
    return T;
}

void r2(int k, int x, int y, int s, int ww)
{
    if (s == 1)
    {
        ans[lb] = make_pair(k, make_pair(x, y));
        lb++;
    }
    u[k] = 2;
    int i, j, v, w = ww;
    for (j = ld[k] - 1; j >= 0; j--)
    {
        v = d[k][j];
        if (!uh[v])
        {
            uh[v] = 1;
            int z;
            for (i = 0; i < lf[v]; i++)
            {
                if (f[v][i] == k) z = i;
                if (!u[f[v][i]])
                    u[f[v][i]] = 1;
            }
            for (i = (z + 1) % lf[v]; f[v][i] != k; i = (i + 1) % lf[v])
                if (u[f[v][i]] == 1)
                {
                    if (w != 0) mx++;
                    w++;
                    r2(f[v][i], mx, y + 1, 1, 0);
                }
        }
    }
    for (i = 0; i < l[k]; i++)
    {
        if (!u[a[k][i]])
        {
            if (w != 0) mx++;
            w++;
            r2(a[k][i], mx, y + 1, 1, 0);
        }
    }
}

void r1(int k, int r)
{
    int i, j, z;
    u[k] = 1;
    for (i = 0; i < l[k]; i++)
    {
        z = a[k][i];
        if (u[z] != 0)
        {
            if (z != r && p3(k, z))
            {
                p = 1;
                h++;
                o = k;
                f[h].push_back(k);
                lf[h]++;
                d[k].push_back(h);
                ld[k]++;
                d[z].push_back(h);
                ld[z]++;
                for (j = lc - 1; c[j] != z; j--)
                {
                    d[c[j]].push_back(h);
                    ld[c[j]]++;
                    f[h].push_back(c[j]);
                    lf[h]++;
                }
                f[h].push_back(z);
                lf[h]++;
            }
        }
        else
        {
            c[lc] = k;
            lc++;
            r1(z, k);
            lc--;
        }
    }
}

