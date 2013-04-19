#include <cstdio>
#include <vector>

using namespace std;

const int N = 500100;
int n, k;
char s[N * 2][5];
int x[N * 2], y[N * 2], d[N], ls[N * 2], lst, t[N * 4], f[N];
vector<int> g[N];

int min_h(int i, int j) {
	return d[i] < d[j] ? i : j;
}

int getmin(int l, int r) {
	int ans = n; d[n] = (1 << 30);
	l += lst; r += lst;
	while (l <= r) {
		if (l & 1) ans = min_h(ans, t[l]);
		if (!(r & 1)) ans = min_h(ans, t[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}

void dfs(int v, int p) {
	ls[lst++] = v;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (to == p)
			continue;
		d[to] = d[v] + 1;
		dfs(to, v);
		ls[lst++] = v;
	}
}

int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%s%d%d", s[i], x + i, y + i);
		x[i]--; y[i]--;
		if (s[i][0] == 'A') {
			g[x[i]].push_back(y[i]);
			g[y[i]].push_back(x[i]);
			n++;
		}
	}
	dfs(0, -1);
	for (int i = lst - 1; i >= 0; i--)
		f[ls[i]] = i;
	for (int i = 0; i < lst; i++)
		t[i + lst] = ls[i];
	for (int i = lst - 1; i > 0; i--)
		t[i] = min_h(t[i + i], t[i + i + 1]);
	for (int i = 0; i < k; i++)
		if (s[i][0] != 'A') {
			int A = x[i], B = y[i];
			A = f[A]; B = f[B];
			if (A > B)
				swap(A, B);
			int lca = getmin(A, B);
			printf("%d\n", lca + 1);
		}
	return 0;
}

