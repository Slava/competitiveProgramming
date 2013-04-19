#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
int n, m, N, M, k[200], a[300], e[200][30], need[30];
int c[30], cost[200], C[300], d[1 << 21];

priority_queue<ii, vector<ii>, greater<ii> >h;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", c + i);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", cost + i, k + i);
		for (int j = 0; j < k[i]; j++)
			scanf("%d", e[i] + j);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", need + i);
	sort(need, need + n);
	for (int i = 0; i < M; i++) {
		C[m] = cost[i];
		for (int j = 0; j < k[i]; j++) {
			if (!binary_search(need, need + n, e[i][j]))
				continue;
			a[m] |= 1 << (lower_bound(need, need + n, e[i][j]) - need);
		}
		if (a[m])
			m++;
	}
	for (int i = 0; i < n; i++) {
		a[m] = (1 << i);
		C[m] = c[need[i]];
		m++;
	}
	for (int i = 1; i < (1 << n); i++)
		d[i] = (1 << 30);
	h.push(ii(0, 0));
	while (!h.empty()) {
		int v = h.top().second, D = h.top().first; h.pop();
		if (d[v] != D)
			continue;
		for (int i = 0; i < m; i++) {
			int to = v | a[i];
			if (d[to] > d[v] + C[i]) {
				d[to] = d[v] + C[i];
				h.push(ii(d[to], to));
			}
		}
	}
	printf("%d\n", d[(1 << n) - 1]);
	return 0;
}

