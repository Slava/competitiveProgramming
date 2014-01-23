#include <cstdio>
#include <algorithm>

using namespace std; 

const int N = 300;
int n, m, k, l[N], r[N], u[N], d[N], x;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		l[i] = u[i] = 1 << 30;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			l[x] = min(l[x], j);
			r[x] = max(r[x], j);
			u[x] = min(u[x], i);
			d[x] = max(d[x], i);
		}
	for (int i = 1; i <= k; i++)
		printf("%d %d %d %d\n", l[i], u[i], r[i] + 1, d[i] + 1);
	return 0;
}
