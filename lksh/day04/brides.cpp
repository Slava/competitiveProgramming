#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 220;
struct edge {
	int x, y, c, f, cost;
} e[8010];

int n, m, k, mm, fr[N], d[N];
double ans;
vector<int> path[110];

bool fordbellman() {
	memset(fr, -1, sizeof fr);
	for (int i = 1; i < n; i++)
		d[i] = (1 << 30);
	d[0] = 0;
	for (int j = 1; j < n; j++)
		for (int i = 0; i < mm; i++)
			if (e[i].c - e[i].f > 0 && d[e[i].y] > d[e[i].x] + e[i].cost) {
				d[e[i].y] = d[e[i].x] + e[i].cost;
				fr[e[i].y] = i;
			}
	return fr[n - 1] != -1;
}

void dfs(int v, int k) {
	for (int i = 0; i < mm; i++)
		if (e[i].x == v && e[i].f == 1 && e[i].c == 1) {
			ans += e[i].cost;
			path[k].push_back(i / 4 + 1);
			e[i].f = 0;
			dfs(e[i].y, k);
			break;
		}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		x--; y--;
		e[mm].x = x; e[mm].y = y; e[mm].cost = z; e[mm].c = 1; e[mm].f = 0; mm++;
		e[mm].x = y; e[mm].y = x; e[mm].cost = -z; e[mm].c = 0; e[mm].f = 0; mm++;
		e[mm].x = y; e[mm].y = x; e[mm].cost = z; e[mm].c = 1; e[mm].f = 0; mm++;
		e[mm].x = x; e[mm].y = y; e[mm].cost = -z; e[mm].c = 0; e[mm].f = 0; mm++;
	}
	for (int Z = 0; Z < k; Z++) {
		if (!fordbellman()) {
			printf("-1\n");
			return 0;
		}
		for (int v = n - 1; fr[v] != -1; v = e[fr[v]].x) {
			e[fr[v]].f++;
			e[fr[v] ^ 1].f--;
		}
	}
	for (int i = 0; i < k; i++)
		dfs(0, i);
	printf("%.6lf\n", ans / k);
	for (int i = 0; i < k; i++) {
		printf("%d", (int)path[i].size());
		for (int j = 0; j < (int)path[i].size(); j++)
			printf(" %d", path[i][j]);
		printf("\n");
	}
	return 0;
}

