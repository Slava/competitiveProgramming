#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 20100;
int n, m, p[N], cnt[N], cut[N], d[N], l[N], u[N], ans[N];
vector<int> g[N];

void dfs(int v) {
    u[v] = cnt[v] = 1;
    vector<int>ch;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        if (to == p[v])
            continue;
        if (!u[to]) {
            p[to] = v; 
            l[to] = d[to] = d[v] + 1;
            dfs(to);
            cnt[v] += cnt[to];
            l[v] = min(l[v], l[to]);
            ch.push_back(to);
        }
        else l[v] = min(l[v], d[to]);
        if (l[to] >= d[v])
            cut[v] = 1;
    }
    if (!p[v] && ch.size() > 1)
        cut[v] = 1;
    if (cut[v]) {
        vector<int> w;
        int sum = 0;
        if (v != 1)w.push_back(n - cnt[v]);
        for (int i = 0; i < (int)ch.size(); i++)
			if (l[ch[i]] >= d[v] || v == 1)
        		w.push_back(cnt[ch[i]]);
			else w[0] += cnt[ch[i]];
		for (int i = 1; i < (int)w.size(); i++)
			sum += w[i];
        for (int i = 1; i < (int)w.size(); i++) {
            ans[v] += w[i - 1] * sum;
            sum -= w[i];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i] + n - 1);
    return 0;
}
