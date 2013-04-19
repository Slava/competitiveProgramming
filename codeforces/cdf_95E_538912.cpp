#include <cstdio>
#include <cstdlib>

const int N = 100100;
int n, m, ans, p[N], c[N], cc[N], a[N];
bool lucky(int x) {
	for (; x; x /= 10)
		if (x % 10 != 4 && x % 10 != 7)
			return false;
	return true;
}

int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

void unite(int x, int y) {
	x = find(x); y = find(y);
	if (rand() & 1)
		p[x] = y;
	else p[y] = x;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		unite(x, y);
	}
	m = 0;
	for (int i = 1; i <= n; i++)
		c[find(i)]++;
	for (int i = 1; i <= n; i++)
		cc[c[i]]++;
	for (int i = 1; i <= n; i++) {
		if (!cc[i])
			continue;
		for (int j = 0; (1 << j) <= cc[i]; j++) {
			a[m] = i * (1 << j); c[m++] = (1 << j); cc[i] -= (1 << j);
		}
		if (cc[i]) {
			a[m] = i * cc[i];
			c[m++] = cc[i];
		}
	}
	for (int i = 1; i <= n; i++)
		cc[i] = (1 << 30);
	cc[0] = 0;
	for (int j = 0; j < m; j++)
		for (int i = n - a[j]; i >= 0; i--)
			if (cc[i + a[j]] > cc[i] + c[j])
				cc[i + a[j]] = cc[i] + c[j];
	ans = (1 << 30);
	for (int i = 1; i <= n; i++)
		if (lucky(i) && ans > cc[i])
			ans = cc[i];
	if (ans == (1 << 30))
		printf("-1");
	else printf("%d", ans - 1);
	return 0;
}





// lang: GNU C++0x
// memory: 4500 KB
// author: imslavko
// submit_date: Jul 9, 2011 11:14:08 AM
// contest: 95
// link: /contest/95/submission/538912
// time: 140 ms
// verdict: Accepted
// problem: 95E - Lucky Country
// ID: 538912
// downloaded by very stupid script
