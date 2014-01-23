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

#define out(x) printf(#x " = %Ld", x)
const int N = 10100;
const int K = 6;
vector<pair<int,int> >g[N];
set<pair<int,int> > q;
int n, m, k, markets[K];
vector<int> marketD[K];
long long dp[1<<K][K][K];

vector<int> dijkstra(int v) {
	q.clear();
	vector<int> d(n, 1<<30);
	d[v] = 0;
	q.insert(pair<int,int>(0,v));

	while (!q.empty()) {
		v = q.begin()->second;
		q.erase(q.begin());

		for (int i = 0; i < (int)g[v].size(); i++) {
			int to = g[v][i].first, w = g[v][i].second;
			if (d[to] > d[v] + w) {
				q.erase(pair<int,int>(d[to], to));
				d[to] =  d[v] + w;
				q.insert(pair<int,int>(d[to], to));
			}
		}
	}

	return d;
}

void upd(long long &a, long long b) {
	if (a > b)
		a = b;
}

bool isMarket[N];

int main() {
	freopen("relocate.in", "r", stdin);
	freopen("relocate.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", markets+i);
		markets[i]--;
		isMarket[markets[i]] = 1;
	}
	
	for (int i = 0; i < m; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		x--; y--;
		g[x].push_back(pair<int,int> (y, w));
		g[y].push_back(pair<int,int> (x, w));
	}

	for (int i = 0; i < (1 << k); i++)
		for (int j = 0; j < k; j++)
			for (int l = 0; l < k; l++)
				dp[i][j][l] = 1LL << 60;

	for (int i = 0; i < k; i++) {
		marketD[i] = dijkstra(markets[i]);
		dp[1<<i][i][i] = 0;
	}

	for (int start = 0; start < k; start++)
		for (int mask = 0; mask < (1 << k); mask++)
			for (int end = 0; end < k; end++) if (mask & (1 << end))
				for (int to = 0; to < k; to++) if (!(mask & (1 << to)))
					upd(dp[mask | (1 << to)][start][to],
						dp[mask][start][end] + marketD[end][markets[to]]);

	long long ans = 1LL << 60;
	for (int i = 0; i < n; i++)
		for (int start = 0; start < k; start++)
			for (int end = 0; end < k; end++) 
				if (start != end && !isMarket[i])
					upd(ans, dp[(1<<k)-1][start][end] + marketD[start][i] + marketD[end][i]);
#ifdef WIN32
	printf("%I64d\n", ans);
#else
	printf("%Ld\n", ans);
#endif

	return 0;
}

