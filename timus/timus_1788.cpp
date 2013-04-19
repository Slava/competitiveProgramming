#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, s, g[200], b[200];

int calc(int k) {
	s = 0;
	for (int i = 0; i < n - k; i++)
		s += g[i];
	for (int i = 0; i < m - k; i++)
		s += b[i] * k;
	return s;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", g + i);
	for (int j = 0; j < m; j++)
		scanf("%d", b + j);
	sort(g, g + n);
	sort(b, b + m);
	int ans = (1 << 30);
	for (int i = 0; i <= min(n, m); i++)
		ans = min(ans, calc(i));
	printf("%d", ans);
	return 0;
}
