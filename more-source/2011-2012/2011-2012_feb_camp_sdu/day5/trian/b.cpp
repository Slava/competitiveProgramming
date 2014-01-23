#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100500;
int n; 
int x[N*10], y[N*10], p[N], m;
int tr[N][3], col[N], d[N], l[N], u[N];
bool bridge[N*10];

int get(int x) {
	if (x == p[x])
		return x;
	return (p[x] = get(p[x]));
}

vector<pair<pair<int,int>,int> > st;
vector<int>g[N];

void dfs(int v, int depth, int p) {
	u[v] = 1;
	d[v] = l[v] = depth;
	for (int i = 0; i < (int)g[v].size(); i++) {
		if (g[v][i] == p) continue;
		int to = x[g[v][i]];
		if (to == v)
			to = y[g[v][i]];
		if (u[to])
			l[v] = min(l[v], d[to]);
		else {
			dfs(to, depth + 1, g[v][i]);
			l[v] = min(l[v], l[to]);
			if (d[v] < l[to])
				bridge[g[v][i]] = 1;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &tr[i][j]);
			if (j)st.push_back(make_pair(make_pair(min(tr[i][j],tr[i][j-1]),max(tr[i][j],tr[i][j-1])),i));
		}
		st.push_back(make_pair(make_pair(min(tr[i][0], tr[i][2]), max(tr[i][0], tr[i][2])), i));
		scanf("%d", &col[i]);
	}

	sort(st.begin(), st.end());
	for (int i = 1; i < (int)st.size(); i++) {
		if (st[i].first == st[i-1].first) {
			int v1 = st[i].second, v2 = st[i-1].second;
			if (col[v1] == col[v2]) {
				if (rand()&1)
					swap(v1,v2);
				p[get(v1)] = get(v2);
//				printf("unite %d, %d\n", get(v1), get(v2));
			}
		}
	}

	for (int i = 1; i < (int)st.size(); i++) {
		if (st[i].first == st[i-1].first) {
			int v1 = get(st[i].second), v2 = get(st[i-1].second);
			if (col[v1] != col[v2]) {
				v1 = col[v1]; v2 = col[v2];
				x[m] = v1;
				y[m] = v2;
				printf("%d %d\n", x[m], y[m]);
				g[v1].push_back(m);
				g[v2].push_back(m);
				m++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (!g[i].empty()) {
			dfs(i,0,-1);
			break;
		}

	int ans = 0;
	for (int i = 0; i < m; i++)
		if (bridge[i])
			ans++;

	printf("%d\n", ans);


	return 0;
}

