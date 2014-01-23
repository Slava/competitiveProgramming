#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const int N = 100001;
pair < int, pair<int, int > > point[N];
vector <int>  a[N], b[N], f[N];
int l[N], lf[N], uh[N], mx, m, n, lpoint, u[N], c[N], p, h, tr = 1, ld[N], lc;
int compare(int k, int z)
{
    int i, j;
    for (i = 0; i < ld[k]; i++)
        for (j = 0; j < ld[z]; j++)
            if (b[k][i] == b[z][j])
                return 0;
    return 1;
}
void search(int k, int r)
{
    int i, j;
    u[k] = 1;
    for (i = 0; i < l[k]; i++)
    {
        if (u[a[k][i]] == 0)
        {
            c[lc] = k;
            lc++;
            search(a[k][i], k);
            lc--;
        }
        else
        {
            if (a[k][i] != r && compare(k, a[k][i]))
            {
                p = 1;
                h++;
                tr = k;
                f[h].pb(k);
                lf[h]++;
                b[k].pb(h);
                ld[k]++;
                b[a[k][i]].pb(h);
                ld[a[k][i]]++;
                for (j = lc - 1; c[j] != a[k][i]; j--)
                {
                    b[c[j]].pb(h);
                    ld[c[j]]++;
                    f[h].pb(c[j]);
                    lf[h]++;
                }
                f[h].pb(a[k][i]);
                lf[h]++;
            }
        }
    }
}
void place(int k, int x, int y, int s, int ww)
{
    u[k] = 2;
    int j = ld[k] - 1, i;
    ld[k]--;
    int v, w = ww;
    if (s == 1)
    {
        point[lpoint] = mp(k, mp(x, y));
        lpoint++;
    }
    if (j >= 0)
    {
        v = b[k][j];
        if (uh[v] == 0)
        {
            uh[v] = 1;
            for (i = 0; i < lf[v]; i++ )
                if (u[f[v][i]] == 0)
                    u[f[v][i]] = 1;
            for (i = 0; i < lf[v]; i++ )
                if (u[f[v][i]] == 1)
                {
                    if (w > 0) mx++;
                    w++;
                    place(f[v][i], mx, y + 1, 1, 0);
                }
        }
        place(k, x, y, 0, w);
    }
    else
    {
        for (i = 0; i < l[k]; i++)
        {
            if (u[a[k][i]] == 0)
            {
                if (w > 0) mx++;
                w++;
                place(a[k][i], mx, y + 1, 1, 0);
            }
        }
    }
}
int main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i, x, y;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        a[x].pb(y);
        l[x]++;
        a[y].pb(x);
        l[y]++;
    }
    search(1, 0);
    for (i = 1; i <= n; i++) u[i] = 0;
    place(tr, 0, 0, 1, 0);
    sort(point, point + lpoint);
    for (i = 0; i < lpoint; i++)
        printf("%d %d\n", point[i].s.f, point[i].s.s);
}
