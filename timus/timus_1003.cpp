#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

#define hashed(i) (Map.find(i) != Map.end())
#define hash(i) Map[i]
#define add(i) Map[i]=++mm;

map<int,int> Map;
int p[20100], n, m, a, b, mm, M = 10000;
char cmd[200];

int get(int x) {
	if (p[x] != x)
		p[x] = get(p[x]);
	return p[x];
}

void unite(int x, int y) {
	x = get(x); y = get(y);
	if (rand() & 1)
		p[x] = y;
	else p[y] = x;
}

int main() {
	for(;;) {
		scanf("%d", &n);
		if (n == -1) return 0;
		scanf("%d", &m); Map.clear(); mm = 0;
		int ans = m;
		for (int i = 0; i < 20100; i++)
			p[i] = i;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%s", &a, &b, cmd);
			if (a < 1 || a > n) ans = min(ans, i);
			if (b < 1 || b > n) ans = min(ans, i);
			if (!hashed(a - 1))
				add(a - 1);
			if (!hashed(b))
				add(b);
			a = hash(a - 1); b = hash(b);
			if (cmd[0] == 'e') {
				if (get(a) == get(b + M) || get(a + M) == get(b))
					ans = min(ans, i);
				unite(a, b); unite(a + M, b + M);
			}
			else {
				if (get(a) == get(b) || get(a + M) == get(b + M))
					ans = min(ans, i);
				unite(a + M, b); unite(a, b + M);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
