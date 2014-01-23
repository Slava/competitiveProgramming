#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int NN = 400009;
const int NNN = 50009;
int t[NN * 4], v[NN * 4], h[NN * 4], n = NN - 2, N;
int M, Mx, My;
int NNNN = n / 2;

void build(int i = 1, int l = 0, int r = n - 1) {
	h[i] = l;
	if (l != r)
		build(i + i, l, (l + r) / 2),
		build(i + i + 1, (l + r) / 2 + 1, r);
}

void update (int l, int r, int d, int i = 1, int tl = 0, int tr = n - 1) {
	if (l == tl && r == tr)
		v[i] += d;
	else {
		v[i+i] += v[i]; 
		v[i+i+1] += v[i];
		v[i] = 0;
		int m = (tl + tr) / 2;
		if (r <= m)
			update (l, r, d, i + i, tl, m);
		else if (l > m)
			update (l, r, d, i + i + 1, m + 1, tr);
		else {
			update (l, m, d, i + i, tl, m);
			update (m + 1, r, d, i + i + 1, m + 1, tr);
		}
		int a = t[i+i] + v[i+i],
			b = t[i+i+1] + v[i+i+1];
		if (a > b)
			t[i] = a, h[i] = h[i+i];
		else t[i] = b, h[i] = h[i+i+1];
	}
}

pii getmax (int l, int r, int i = 1, int tl = 0, int tr = n - 1, int pl = 0) {
	pl += v[i];
	if (tl == l && tr == r)
		return make_pair(t[i] + pl, h[i]);
	int m = (tl + tr) / 2;
	if (r <= m)
		return getmax(l, r, i + i, tl, m, pl);
	if (l > m)
		return getmax(l, r, i + i + 1, m + 1, tr, pl);
	pii a, b;
	a = getmax(l, m, i + i, tl, m, pl);
	b = getmax(m + 1, r, i + i + 1, m + 1, tr, pl);
	if(a >= b)
		return a;
	return b;
}

struct seg {
	int y1, y2, x, d;
	seg(int _x, int _y1, int _y2, int _d) {
		x = _x; d = _d;
		y1 = _y1; y2 = _y2;
	}
};
vector<seg> segment;

bool cmp(const seg &a, const seg &b) {
	if (a.x < b.x || (a.x == b.x && a.d > b.d))
		return 1;
	return 0;
}

int main () {
	build();
	scanf ("%d", &N);
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++) {
		scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
		seg t(x1, y1, y2, 1);
		segment.push_back(t);
		seg e(x2, y1, y2, -1);
		segment.push_back(e);
	}
	sort(segment.begin(), segment.end(), cmp);
	
	for (vector<seg>::iterator i = segment.begin();
			i != segment.end(); ++i) {
		update(i->y1 + NNNN, i->y2 + NNNN, i->d);
		pii t = getmax(0, n - 1);
		if (t.first > M) {
			M = t.first;
			Mx = i->x;
			My = t.second - NNNN;
		}
	}
	printf("%d\n%d %d", M, Mx, My);

	return 0;
}
