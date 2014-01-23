#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define mp make_pair

const int maxN = 260001;
int n, m, N;
char s[600][600];
vector<pair<int,int> > g[maxN];
int q0[maxN], q1[maxN], inQueue[maxN], d[maxN], h0, t0, h1, t1;
int inf = 1<<30;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	N = (n + 1) * (m + 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if ((s[i][j] == '/')) {
				g[i*(m+1)+j+1].push_back(mp((i+1)*(m+1)+j,0)),
				g[(i+1)*(m+1)+j].push_back(mp(i*(m+1)+j+1,0));
				g[i*(m+1)+j].push_back(mp((i+1)*(m+1)+j+1,1)),
				g[(i+1)*(m+1)+j+1].push_back(mp(i*(m+1)+j,1));
			}
			else {
				g[i*(m+1)+j].push_back(mp((i+1)*(m+1)+j+1,0)),
				g[(i+1)*(m+1)+j+1].push_back(mp(i*(m+1)+j,0));
				g[i*(m+1)+j+1].push_back(mp((i+1)*(m+1)+j,1)),
				g[(i+1)*(m+1)+j].push_back(mp(i*(m+1)+j+1,1));
			}
		}

	fill(d+1,d+N,inf);
	fill(inQueue+1, inQueue+N, -1);

	q0[t0++] = 0;

	while (h0 < t0 || h1 < t1) {
		int v;
		if (h0 < t0)
			v = q0[h0++];
		else v = q1[h1++];
		if (inQueue[v] == 2)
			continue;
		inQueue[v] = 2;
		for (int i = 0; i < (int)g[v].size(); i++) {
			int to = g[v][i].first, w = g[v][i].second;
			if (d[to] > d[v] + w) {
				d[to] = d[v] + w;
				if (!w && inQueue[to] != 0 && inQueue[to] != 2) {
					q0[t0++] = to;
					inQueue[to] = 0;
				}	
				if (w && inQueue[to] == -1) {
					q1[t1++] = to;
					inQueue[to] = 1;
				}	
			}
		}
	}

	if (d[N-1] != inf)
		printf("%d\n", d[N-1]);
	else puts("NO SOLUTION");

	return 0;
}

