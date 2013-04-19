#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

#define f first
#define s second
const int N = 61;
int n, m, r, s, t, k;
int g[N][N][N], d[N][N], dm[N][N], dt[N][N];
int ans[100010];
vector<pair<pair<int,int>,int> > Q[1010];


void floyd(int a[N][N]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                a[j][k] = min(a[j][i]+a[i][k], a[j][k]);
}

int main() {
    scanf("%d%d%d", &n, &m, &r);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = (int)1e9;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            for (int l = 0; l < n; l++)
                scanf("%d", &g[i][j][l]);
        floyd(g[i]);
        /*
        printf("for %dth car:\n", i);
        for (int j = 0; j < n; j++)
            for (int l = 0; l < n; l++)
                printf("%d%c", g[i][j][l], " \n"[l==n-1]);
        */
        for (int j = 0; j < n; j++)
            for (int l = 0; l < n; l++)
                dm[j][l] = d[j][l] = min(d[j][l], g[i][j][l]);
    }

    for (int q = 0; q < r; q++) {
        scanf("%d%d%d", &s, &t, &k);
        s--; t--;
        Q[k].push_back(make_pair(make_pair(s, t), q));
    }

    for (int q = 0; q < 1010; q++) {
        for (int i = 0; i < (int)Q[q].size(); i++) {
            s = Q[q][i].f.f; t = Q[q][i].f.s;
            ans[Q[q][i].s] = d[s][t];
        }

        if (q > n*2)
            continue;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dt[i][j] = d[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    d[i][j] = min(d[i][j], dt[i][k] + dm[k][j]);
        /*
        printf("after %d\n", q);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf("%d%c", d[i][j], " \n"[j==n-1]);
    
        */
    }

    for (int i = 0; i < r; i++)
        printf("%d\n", ans[i]);

    return 0;
}




// lang: GNU C++
// memory: 5200 KB
// author: imslavko
// submit_date: May 10, 2012 10:06:12 PM
// contest: 187
// link: /contest/187/submission/1678981
// time: 270 ms
// verdict: Accepted
// problem: 187B - AlgoRace
// ID: 1678981
// downloaded by very stupid script
