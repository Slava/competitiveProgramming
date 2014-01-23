#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N = 10009;
char s[100];
vector <int > a[N], w[N];
int l, n, r, lp[N][20], ld[N][20];
int lvl[N], p[N], d[N], ln;
bool A(char x) { return (x >= '0' && x <= '9'); }
void dfs(int k, int level, int lg) {
    if ((1 << lg) == level - 1) lg++;
    int i, al, j;
    lvl[k] = level;
    for (i = 0; i < lg; i++) {
        if (i == 0) {
            ld[k][i] = d[k];
            lp[k][i] = p[k];
        }
        else {
            ld[k][i] = ld[lp[k][i - 1]][i - 1] + ld[k][i - 1];
            lp[k][i] = lp[lp[k][i - 1]][i - 1];
        }
    }
    al = a[k].size();
    for (i = 0; i < al; i++) {
        j = a[k][i];
        if (lvl[j] == 0) {
            p[j] = k;
            d[j] = w[k][i];
            dfs(j, level + 1, lg);
        }
    }
}
int dist(int x, int y) {
    int i, x1 = x, y1 = y, ans = 0;
    if (lvl[x] < lvl[y]) swap(x, y);
    for (i = ln; i >= 0; i--)
        if (lp[x][i] != 0)
            if (lvl[lp[x][i]] >= lvl[y]) {
                ans += ld[x][i];
                x = lp[x][i];
            }
    if (x == y) return ans;
    for (i = ln; i >= 0; i--)
        if (lp[x][i] != 0 && lp[x][i] != lp[y][i]) {
            ans += ld[x][i] + ld[y][i];
            x = lp[x][i];
            y = lp[y][i];
        }
    return ans + d[x] + d[y];
}
int kth(int x, int y, int k) {
    int i, j, x1 = x, y1 = y, l;
    if (k == 1) return x;
    if (lvl[x] < lvl[y])
        swap(x, y);
    for (i = ln; i >= 0; i--)
        if (lp[x][i] != 0)
            if (lvl[lp[x][i]] >= lvl[y])
                x = lp[x][i];
    if (x == y) r = x;
    else {
        for (i = ln; i >= 0; i--)
            if (lp[x][i] != 0 && lp[x][i] != lp[y][i]) {
                x = lp[x][i];
                y = lp[y][i];
            }
        r = p[x];
    }
    x = x1; y = y1;
    l = lvl[x] - lvl[r] + 1;
    j = lvl[x] - lvl[r] * 2 + lvl[y] + 1;
    if (k == j) return y;
    if (k == l) return r;
    if (k > l) {
        k = j - k;
        for (i = ln; i >= 0; i--) {
            x = lp[y][i];
            j = lvl[y] - lvl[x];
            if (x != 0)
                if (j <= k) {
                    y = x;
                    k -= j;
                }
        }
        return y;
    }
    else {
        k--;
        for (i = ln; i >= 0; i--) {
            y = lp[x][i];
            j = lvl[x] - lvl[y];
            if (y != 0)
                if (j <= k) {
                    x = y;
                    k -= j;
                }
        }
        return x;
    }
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int i, x, k, y, t, j;
    scanf("%d", &t);
    for ( ; t > 0; t--) {
        scanf("%d", &n);
        for (ln = 0; (1 << ln) <= n; ln++);
        if (n == 1) ln = -1;
        for (i = 1; i < n; i++) {
            scanf("%d %d %d", &x, &y, &k);
            a[x].pb(y); w[x].pb(k);
            a[y].pb(x); w[y].pb(k);
        }
        dfs(1, 1, 0);
        for ( ; ; ) {
            scanf("%s", s);
            if (s[1] == 'I') {
                scanf("%d %d", &x, &y);
                cout << dist(x, y) << "\n";
            }
            if (s[1] == 'T') {
                scanf("%d %d %d", &x, &y, &k);
                cout << kth(x, y, k) << "\n";
            }
            if (s[1] == 'O') break;
        }
        for (i = 1; i <= n; i++) {
            a[i].clear();
            lvl[i] = 0;
            w[i].clear();
            for (j = 0; j <= ln; j++)
                lp[i][j] = ld[i][j] = 0;
        }
    }
    return 0;
}
