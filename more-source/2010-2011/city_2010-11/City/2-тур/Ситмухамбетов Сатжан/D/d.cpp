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
vector < int >  a[N], d[N], f[N];
int l[N], u[N], c[N], p, h, o = 1, ld[N], lc, lf[N], uh[N];
int pr1(int k, int z) {
    int i, j;
    for (i = 0; i < ld[k]; i++)
        for (j = 0; j < ld[z]; j++)
            if (d[k][i] == d[z][j])
                return 0;
    return 1;
}
int mx, m, n, lb;
pair < int, pair<int, int > > b[N];
void d2(int k, int x, int y, int s, int ww) {
    if (s == 1) {
        b[lb] = mp(k, mp(x, y));
        lb++;
    }
    u[k] = 2;
    int j, i;
    int v, w = ww;
    for (j = ld[k] - 1; j >= 0; j--) {
        v = d[k][j];
        if (uh[v] == 0) {
            uh[v] = 1;
            int z;
            for (i = 0; i < lf[v]; i++) {
                if (f[v][i] == k) z = i;
                if (u[f[v][i]] == 0)
                    u[f[v][i]] = 1;
            }
            for (i = (z + 1) % lf[v]; f[v][i] != k; i = (i + 1) % lf[v])
                if (u[f[v][i]] == 1) {
                    if (w > 0) mx++;
                    w++;
                    d2(f[v][i], mx, y + 1, 1, 0);
                }
        }
    }
    for (i = 0; i < l[k]; i++) {
        if (u[a[k][i]] == 0) {
            if (w > 0) mx++;
            w++;
            d2(a[k][i], mx, y + 1, 1, 0);
        }
    }
}
void d1(int k, int r) {
    int i, j, z;
    u[k] = 1;
    for (i = 0; i < l[k]; i++) {
        z = a[k][i];
        if (u[z] > 0) {
            if (z != r && pr1(k, z)) {
                p = 1;
                h++;
                o = k;
                f[h].pb(k); lf[h]++;
                d[k].pb(h); ld[k]++; d[z].pb(h); ld[z]++;
                for (j = lc - 1; c[j] != z; j--) {
                    d[c[j]].pb(h); ld[c[j]]++;
                    f[h].pb(c[j]); lf[h]++;
                }
                f[h].pb(z); lf[h]++;
            }
       }
        else {
            c[lc] = k;
            lc++;
            d1(z, k);
            lc--;
        }
    }
}
int main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i, x, y;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        a[x].pb(y);
        l[x]++;
        a[y].pb(x);
        l[y]++;
    }
    d1(1, 0);
    for (i = 1; i <= n; i++) u[i] = 0;
    d2(o, 0, 0, 1, 0);
    sort(b, b + lb);
    for (i = 0; i < lb; i++)
        printf("%d %d\n", b[i].s.f, b[i].s.s);
}
