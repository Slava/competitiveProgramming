#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct edge {
	int a, b, x;
	edge() { x = -(1 << 30); }
}e[1000010];
bool operator < (edge a, edge b) {
	return a.x < b.x;
}
int n, m, q, c, p[100010], an[1000010], mm;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int a, int b) {
	a = find(a); b = find(b);
	c--;
	if (rand() & 1)
		p[a] = b;
	else p[b] = a;
}

int main() {
	scanf("%d%d", &n, &m); c = n;
	for (int i = 0; i < m; i++)
		scanf("%d%d", &e[i].a, &e[i].b);
	scanf("%d", &q);
	for (int i = 0, x; i < q; i++) {
		scanf("%d", &x);
		e[--x].x = -i;
	}
	sort(e, e + m);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		if (e[i].x != -(1 << 30))
			an[mm++] = c;
		if (find(e[i].a) != find(e[i].b))
			unite(e[i].a, e[i].b);
	}
	for (int i = mm - 1; i >= 0; i--)
		printf("%d ", an[i]);
	return 0;
}

