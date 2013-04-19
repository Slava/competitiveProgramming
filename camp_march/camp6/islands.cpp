#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 510;
const int M = N * N * 8;
char map[N][N];
int n, m, a[N][N], k, qx[N * N], qy[N * N], h, t, d[] = {0,1, 0,-1, 1,0, -1,0}, mm, p[M], ans, oo;
struct edge {
	int x, y, c;
} g[M];
bool edgecmp (edge a, edge b)	{	return a.c < b.c;	}

bool can (int x, int y)	{	return x >= 0 && x < n && y >= 0 && y < m && !a[x][y] && map[x][y] == '1';	}
void bfs (int x, int y, int c) {
	h = t = 0;
	qx[t] = x, qy[t++] = y;
	a[x][y] = c;
	while (h < t)
	{
		for (int i = 0; i < 8; i += 2)
			if (can(qx[h] + d[i], qy[h] + d[i + 1]))
			{
				qx[t] = qx[h] + d[i], qy[t] = qy[h] + d[i + 1];
				a[qx[t]][qy[t]] = c; t++;
			}
		h++;
	}
}

int find (int x) {
	if (x != p[x])
		p[x] = find(p[x]);
	return p[x];
}

void Union (int x, int y) {
	x = find (x);
	y = find (y);
	if (rand()&1)
		p[x] = y;
	else p[y] = x;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf ("%s", map[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!a[i][j] && map[i][j] == '1')
				bfs(i, j, ++k);
	for (int i = 0; i < n; i++) {
		int cur = 0, pr;
		for (int j = 0; j < m; j++)
			if (a[i][j] && map[i][j] == '1') {
				if (cur) {
					g[mm].c = j - pr - 1;
					g[mm].x = a[i][j]; g[mm++].y = cur;
				}
				cur = a[i][j];
				pr = j;
			}
	}
	for (int j = 0; j < m; j++) {
		int cur = 0, pr;
		for (int i = 0; i < n; i++)
			if (a[i][j] && map[i][j] == '1') {
				if (cur){
					g[mm].c = i - pr - 1;
					g[mm].x = a[i][j]; g[mm++].y = cur;
				}
				cur = a[i][j];
				pr = i;
			}
	}
	sort (g, g + mm, edgecmp);
	for (int i = 1; i <= k; i++)
		p[i] = i;
	for (int i = 0; i < mm; i++)
		if (find(g[i].x) != find(g[i].y)) {
			Union(g[i].x, g[i].y);
			ans += g[i].c;
			oo++;
		}
	if (oo != k - 1)
		puts("-1");
	else printf ("%d\n", ans);
	return 0;
}

