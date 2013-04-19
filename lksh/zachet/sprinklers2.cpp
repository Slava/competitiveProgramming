#include <cstdio>
#include <cstdlib>

const int N = 50100;
int n, m, k, p[N], x[N*3], y[N*3], ans[N*3];
char s[N*3][5];

int get(int x) {
	if (p[x] != x)
		p[x] = get(p[x]);
	return p[x];
}

void unite(int x, int y) {
	if (rand() & 1)
		p[x] = y;
	else p[y] = x;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < m * 2; i++)
		scanf("%d", x);
	for (int i = 0; i < k; i++)
		scanf("%s%d%d", s + i, x + i, y + i);
	m = 0;
	for (int i = k - 1; i >= 0; i--)
		if (s[i][0] == 'a')
			ans[m++] = get(x[i]) == get(y[i]);
		else unite(get(x[i]), get(y[i]));
	for (int i = m - 1; i >= 0; i--)
		printf("%s\n", ans[i] ? "YES" : "NO");
	return 0;
}
