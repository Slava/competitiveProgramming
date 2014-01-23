#include <cstdio>
#include <cstdlib>
int abs(int x) {
	return x < 0 ? -x : x;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

int n;
bool g[110][110][3][3];

struct pt {
	int x, y;
};

struct tr {
	pt a[3];
}a[110];

int Area(pt a, pt b, pt c) {
	return abs(a.y * (b.x - c.x) + b.y * (c.x - a.x) + c.y * (a.x - b.x));
}

bool intr(pt a, pt b, pt c, pt x) {
	return Area(a,b,c) == Area(a,b,x) + Area(a,x,c) + Area(x,b,c);
}
int square (pt a, pt b, pt c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}
bool intersect_1 (int a, int b, int c, int d) {
	return max (a, b) >= min (c, d) && max (c, d) >= min (a, b);
}
bool intersect (pt a, pt b, pt c, pt d) {
	int s11 = square (a, b, c);
	int s12 = square (a, b, d);
	int s21 = square (c, d, a);
	int s22 = square (c, d, b);
	if (s11 == 0 && s12 == 0 && s21 == 0 && s22 == 0)
		return intersect_1 (a.x, b.x, c.x, d.x)
			&& intersect_1 (a.y, b.y, c.y, d.y);
	else
		return (s11 * s12 <= 0) && (s21 * s22 <= 0);
}

bool elka(pt a, pt b, pt c, pt x, pt y, pt z) {
	return intr(a,b,c,x) && !intr(a,b,c,y) && !intr(a,b,c,z) &&
		intersect(b,c,x,y) && intersect(b,c,x,z);
}

int u[110][3];
int d[110][3];

int dfs(int v, int k) {
	if (u[v][k] == 2)
		return d[v][k];

	for (int i = 0; i < n; i++)
		if (v != i)
			for (int j = 0; j < 3; j++)
				if (g[v][i][k][j])
					if (u[i][j] == 1) {
						puts("-1");
						exit(0);
					}
					else d[v][k] = max(d[v][k], 1 + dfs(i,j));

	return d[v][k];
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d%d", &a[i].a[j].x, &a[i].a[j].y);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++) 
						g[i][j][k][l] = elka(a[i].a[k], a[i].a[(k+1)%3], a[i].a[(k+2)%3], a[j].a[l], a[j].a[(l+1)%3], a[j].a[(l+2)%3]);

	int ans = 0;
	for (int i = 0; i < n; i++)
		for ( int j = 0; j < 3; j++ )
			ans = max(ans, dfs(i,j));
	printf("%d\n", ans);

	return 0;
}
