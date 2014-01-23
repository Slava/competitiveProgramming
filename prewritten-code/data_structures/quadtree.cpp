/*
quadtree
+--------+
|1__|__3 |
|2  |  4 |
+--------+
по рассказам Мадияра аби
Летняя Школа Программирования
КБТУ - Алматы, 2011 июнь
*/
#include <cstdio>
#include <cstdlib>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)

const int N = 256;
int t[N * N * 2], n = 256, a[N][N];
void build(int i = 1, int l = 0, int r = n - 1, int u = 0, int d = n - 1) {
	if (l == r && d == u)
		t[i] = a[l][d];
	else {
		int m = (l + r) / 2,
			v = (u + d) / 2;
		build(i * 4, l, m, u, v);
		build(i * 4 + 1, l, m, v + 1, d);
		build(i * 4 + 2, m + 1, r, u, v);
		build(i * 4 + 3, m + 1, r, v + 1, d);
		t[i] = t[i * 4] + t[i * 4 + 1] + t[i * 4 + 2] + t[i * 4 + 3];
	}
}

int get(int l, int r, int u, int d, int i = 1, int tl = 0, int tr = n - 1, int tu = 0, int td = n - 1) {
	if (r < l || d < u)
		return 0;
	if (l == tl && r == tr && u == tu && d == td) 
		return t[i];
	int m = (tl + tr) / 2,
		v = (tu + td) / 2;
	return 
		get(l, min(r, m), u, min(v, d), i * 4, tl, m, tu, v) +
		get(l, min(r, m), max(u, v + 1), d, i * 4 + 1, tl, m, v + 1, td) +
		get(max(m + 1, l), r, u, min(v, d), i * 4 + 2, m + 1, tr, tu, v) +
		get(max(m + 1, l), r, max(u, v + 1), d, i * 4 + 3, m + 1, tr, v + 1, td);
}

void update(int I, int J, int x, int i = 1, int tl = 0, int tr = n - 1, int tu = 0, int td = n - 1) {
	if (tl == tr && tu == td)
		t[i] = x;
	else {
		int m = (tl + tr) / 2,
			v = (tu + td) / 2;
		if (I <= m && J <= v)
			update(I, J, x, i * 4, tl, m, tu, v);
		else if (I <= m && J > v)
			update(I, J, x, i * 4 + 1, tl, m, v + 1, td);
		else if (I > m && J <= v)
			update(I, J, x, i * 4 + 2, m + 1, tr, tu, v);
		else update(I, J, x, i * 4 + 3, m + 1, tr, v + 1, td);
		t[i] = t[i * 4] + t[i * 4 + 1] + t[i * 4 + 2] + t[i * 4 + 3];
	}
}

int sum(int l, int r, int u, int d) {
	int R = 0;
	for (int i = l; i <= r; i++)
		for (int j = u; j <= d; j++)
			R += a[i][j];
	return R;
}

int main() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand();
	build();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = i; k < n; k++)
				for (int l = j; l < n; l++)
					if (sum(i,k,j,l) != get(i,k,j,l))
					{
						printf("%d != %d\n",
						sum(i,k,j,l),
						get(i,k,j,l));
					}
	return 0;
}

