#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif
const int N = 100100;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define forc(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
int n, m, u[N]; long long d[N];
vector<pair<int,long long> >g[N], bg[N];

void NO() {
    puts("NO");
    exit(0);
}

void go(int v) {
  //  fprintf(stderr, "v= %d %lld\n", v, d[v]);
    u[v] = 1; long long tk = d[v];
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i].first;
        long long pl = g[v][i].second;
        if (u[to]) {
            if (d[to] != tk + pl) {
               // cout << to << "  " << d[to] <<  "   != " << tk << "  " << pl << endl;
                NO();
            }
        }
        else {
            d[to] = tk + pl;
            go(to);
        }
    }
    for (int i = 0; i < (int)bg[v].size(); i++) {
        int to = bg[v][i].first;
        long long pl = bg[v][i].second;
        if (u[to]) {
            if (d[to] != tk + pl) {
            //    cout << to << "  " << d[to] <<  "   != " << tk << "  " << pl << endl;NO();
                NO();
            }
        }
        else {
            d[to] = tk + pl;
            go(to);
        }
    }
}

void dfs(int v) {
    u[v] = 1;
    forc(i, g[v]) {
        if (!i->s)continue;
        if (u[i->f] == 1) {
           // fprintf(stderr, "cycle %d %d\n", v, i->f);
            NO();
        }
        if (!u[i->f]) {
            dfs(i->f);
        }
    }
    u[v] = 2;
}

int main() {
    //scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;long long z; //scanf("%d%d%lld", &x, &y, &z);
        cin >> x >> y >> z;
      //scanf("%d%d" i64, &x, &y, &z);
        g[x].push_back(mp(y, z));
        bg[y].push_back(mp(x, -z));
      //  fprintf(stderr, "edge %d %d %lld\n", x, y, z);
    }
    for (int i = 1; i <= n; i++)
        if (!u[i])dfs(i);
    memset(u, 0, sizeof u);
    for (int i = 1; i <= n; i++)
        if (!u[i])go(i);

	puts("YES");
	return 0;
}
