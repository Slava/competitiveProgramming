#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
const int N = 100009;
vector < int >  rebra[N], ver[N], f[N];
int len[N], used[N], c[N], p, h, o = 1, lend[N], lenc, lenf[N], uh[N];
int pr1(int k, int z) {
    int i, j;
    for (i = 0; i < lend[k]; i++)
        for (j = 0; j < lend[z]; j++)
            if (ver[k][i] == ver[z][j])
                return 0;
    return 1;
}
void d1(int k, int r) {
    int i, j, z;
    used[k] = 1;
    for (i = 0; i < len[k]; i++)
    {
        z = rebra[k][i];
        if (used[z] == 0)
        {
            //printf("z = %d\n", z);
            c[lenc] = k;
            lenc++;
            d1(z, k);
            lenc--;
        }
        else
        {
            if (z != r && pr1(k, z))
            {
                p = 1;
                h++;
                o = k;
                f[h].pb(k); lenf[h]++;
                ver[k].pb(h); lend[k]++; ver[z].pb(h); lend[z]++;
                for (j = lenc - 1; c[j] != z; j--) {
                    ver[c[j]].pb(h); lend[c[j]]++;
                    f[h].pb(c[j]); lenf[h]++;
                }
                f[h].pb(z); lenf[h]++;
            }
        }
    }
}
int mx, m, n, lenb;
pair < int, pair<int, int > > b[N];
bool pr(int k, int l) {
    int i;
    for (i = 0; i < lend[k]; i++)
        if (ver[k][i] == l)
            return 1;
    return 0;
}
void d2(int k, int x, int y, int s, int ww)
{
    if (s == 1)
    {
        b[lenb] = mp(k, mp(x, y));
        lenb++;
    }
    used[k] = 2;
    int j = lend[k] - 1, i; lend[k]--;
    int v, w = ww;
    if (j >= 0)
    {
        v = ver[k][j];
        if (uh[v] == 0)
        {
            uh[v] = 1;
            for (i = 0; i < lenf[v]; i++ )
                if (used[f[v][i]] == 0)
                    used[f[v][i]] = 1;
            for (i = 0; i < lenf[v]; i++ )
                if (used[f[v][i]] == 1)
                {
                    if (w > 0) mx++;
                    w++;
                    d2(f[v][i], mx, y + 1, 1, 0);
                }
        }
        d2(k, x, y, 0, w);
    }
    else
    {
        for (i = 0; i < len[k]; i++)
        {
            if (used[rebra[k][i]] == 0)
            {
                if (w > 0) mx++;
                w++;
                d2(rebra[k][i], mx, y + 1, 1, 0);
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
            rebra[x].pb(y);
            len[x]++;
            rebra[y].pb(x);
            len[y]++;
    }
    d1(1, 0);
    for (i = 1; i <= n; i++) used[i] = 0;
    d2(o, 0, 0, 1, 0);
    sort(b, b + lenb);
    for (i = 0; i < lenb; i++)
        printf("%d %d\n", b[i].s.f, b[i].s.s);
}
