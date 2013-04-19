#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1024;
int t[1000 * 1000 * 2], f[1000 * 1000 * 2];

int sum(int i, int l, int r, int u, int d) {
	if (f[i] != -1)
		return f[i] * (r - l + 1) * (d - u + 1);
	return t[i];
}

void upd(int l, int r, int u, int d, int x, int i = 1, int tl = 1, int tr = N, int tu = 0, int td = N) {
	if (l > r || u > d)
		return;
	if (l == tl && r == tr && u == tu && d== td) {
		f[i] = x;
		t[i] = x * (r - l + 1) * (d - u + 1);
	}
	f[i * 4] = f[i * 4 + 1] = f[i * 4 + 2] = f[i * 4 + 3] = f[i];
	f[i] = -1;
	int tx = (tl + tr) / 2, ty = (tu + td) / 2;
	upd(l, min(r, tx), u, min(d, ty), x, i * 4, tl, tx, tu, ty);
	upd(l, min(r, tx), max(u, ty + 1), d, x, i * 4 + 1, tl, tx, ty + 1, td);
	upd(max(l, tx + 1), r, u, min(d, ty), x, i * 4 + 2, tx + 1, tr, tu, ty);
	upd(max(l, tx + 1), r, max(u, ty + 1), d, x, i * 4 + 3, tx + 1, tr, ty + 1, td);
	t[i] = sum(i * 4, tl, tx, tu, ty) + sum(i * 4 + 1, tl, tx, ty + 1, td) +
		sum(i * 4 + 2, tx + 1, tr, tu, ty) + sum(i * 4 + 3, tx + 1, tr, ty + 1, td);
}


int get(int l, int r, int u, int d, int i = 1, int tl = 1, int tr = N, int tu = 0, int td = N) {
	if (l > r || u > d)
		return 0;
	if (l == tl && r == tr && u == tu && d== td)
		return sum(i, l, r, u, d);
	f[i * 4] = f[i * 4 + 1] = f[i * 4 + 2] = f[i * 4 + 3] = f[i];
	f[i] = -1;
	int tx = (tl + tr) / 2, ty = (tu + td) / 2;
	int ans = 
	get(l, min(r, tx), u, min(d, ty), i * 4, tl, tx, tu, ty) +
	get(l, min(r, tx), max(u, ty + 1), d, i * 4 + 1, tl, tx, ty + 1, td) +
	get(max(l, tx + 1), r, u, min(d, ty), i * 4 + 2, tx + 1, tr, tu, ty) +
	get(max(l, tx + 1), r, max(u, ty + 1), d, i * 4 + 3, tx + 1, tr, ty + 1, td);
	t[i] = sum(i * 4, tl, tx, tu, ty) + sum(i * 4 + 1, tl, tx, ty + 1, td) +
		sum(i * 4 + 2, tx + 1, tr, tu, ty) + sum(i * 4 + 3, tx + 1, tr, ty + 1, td);
	return ans;
}

int main() {
	int n, m, l, r, u, d;
	char c;
	scanf("%d%d", &n, &m);
	upd(1,n,1,n,1);
	printf("%d\n", get(1,n,1,n));
	return 0;
}


