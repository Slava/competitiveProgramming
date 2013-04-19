//305 exhibition
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

const int N = 400;
int n, m, a[N], b[N], st[N], u[N], ans[N];
map<int,int>to;

bool dfs(int v) {
	if (u[v]) return false;
	u[v] = true;
	for (int i = st[v]; ; ++i) {
		long long t = (long long) a[v] * i + b[v];
		if (t < 1 || t > m) break;
		if (!to[t] || dfs(to[t])) {
			to[t] = v;
			ans[v] = t;
			return true;
		}
		if (!a[v]) break;
	}
	return false;
}

int main() {
	memset(ans, -1, sizeof ans);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", a + i, b + i);
		if (a[i] < 0)
			st[i] = (m - b[i]) / a[i];
		if (a[i] > 0)
			st[i] = (1 - b[i]) / a[i];
		if (st[i] < 0)
			st[i] = 0;
		while(a[i] < 0 && (long long)st[i] * a[i] + b[i] > m)st[i]++;
		while(a[i] > 0 && (long long)st[i] * a[i] + b[i] < 1)st[i]++;
	}
	for (int i = 1; i <= n; i++) {
		memset(u, 0, sizeof u);
		dfs(i);
	}
	for (int i = 1, j = 1; i <= n; i++) {
		if (ans[i] == -1) {
			while(to.count(j) && ans[to[j]] == j)
				j++;
			ans[i] = j++;
		}
		printf("%d ", ans[i]);
	}
	return 0;
}


