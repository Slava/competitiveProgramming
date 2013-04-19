#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int n, m, d[101010], l[101010], u[101010], was[301010];
vector<int>g[101010], a[101010];
pair<int,int>e[301010];


void dfs1(int v, int p = 0) {
    u[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (!u[g[v][i]]) {
            dfs1(g[v][i], v);
            a[v].push_back(g[v][i]);
        }
        else if (g[v][i] != p && u[g[v][i]] == 1) {
            a[v].push_back(g[v][i]);
        }
    u[v] = 2;
}

void dfs(int v, int p) {
    u[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        if (to == p)
            continue;
        if (!u[to]) {
            d[to] = l[to] = d[v] + 1;
//            a[v].push_back(to);
            dfs(to, v);
            if (l[v] > l[to])
                l[v] = l[to];
        }
        else if (l[v] > d[to])
                l[v] = d[to];
        if (l[to] > d[v]) {
            printf("0\n");
            exit(0);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        if (x > y)swap(x,y);
        e[i] = make_pair(x,y);
    }
    sort(e,e + m);

    dfs(1, 0);

    memset(u, 0, sizeof u);
    dfs1(1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < a[i].size(); j++) {
            printf("%d %d\n", i, a[i][j]);
            int x = i, y = a[i][j];
            if (x > y)swap(x,y);
            was[lower_bound(e, e + m, make_pair(x,y)) - e] = 1;
           // printf(">> %d\n",lower_bound(e, e + m, make_pair(x,y)) - e);
        }
    for (int i = 0; i < m; i++)
        if (!was[i])
            printf("%d %d\n", e[i].first, e[i].second);


    return 0;
}




// lang: GNU C++
// memory: 19800 KB
// author: imslavko
// submit_date: Oct 7, 2011 8:38:28 PM
// contest: 118
// link: /contest/118/submission/746765
// time: 720 ms
// verdict: Accepted
// problem: 118E - Bertown roads
// ID: 746765
// downloaded by very stupid script
